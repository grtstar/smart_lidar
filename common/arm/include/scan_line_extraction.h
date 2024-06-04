//
// Created by suxuan on 18-7-12.
//

#ifndef SCAN_LINE_EXTRACTION_SCAN_LINE_EXTRACTION_H
#define SCAN_LINE_EXTRACTION_SCAN_LINE_EXTRACTION_H
#include <vector>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <boost/array.hpp>
#include "Eigen/Dense"


#include "mars_message/LaserScan.hpp"


using namespace std;

struct CachedData
{
    std::vector<unsigned int> indices;
    std::vector<double> bearings;
    std::vector<double> cos_bearings;
    std::vector<double> sin_bearings;
};

struct RangeData
{
    std::vector<double> ranges;
    std::vector<double> xs;
    std::vector<double> ys;
};

struct Params
{
    double bearing_var;
    double range_var;
    double least_sq_angle_thresh;
    double least_sq_radius_thresh;
    double max_line_gap;
    double min_line_length;
    double min_range;
    double min_split_dist;
    double outlier_dist;
    unsigned int min_line_points;
};

struct PointParams
{
    std::vector<double> a;
    std::vector<double> ap;
    std::vector<double> app;
    std::vector<double> b;
    std::vector<double> bp;
    std::vector<double> bpp;
    std::vector<double> c;
    std::vector<double> s;
};

class Line
{

public:
    // Constructor / destructor
    Line(const CachedData&, const RangeData&, const Params&, std::vector<unsigned int>);
    Line(double angle, double radius, const boost::array<double, 4> &covariance,
         const boost::array<double, 2> &start, const boost::array<double, 2> &end,
         const std::vector<unsigned int> &indices);
    ~Line();
    // Get methods for the line parameters
    double                           getAngle() const;
    const boost::array<double, 4>&   getCovariance() const;
    const boost::array<double, 2>&   getEnd() const;
    const std::vector<unsigned int>& getIndices() const;
    double                           getRadius() const;
    const boost::array<double, 2>&   getStart() const;
    // Methods for line fitting
    double       distToPoint(unsigned int);
    void         endpointFit();
    void         leastSqFit();
    double       length() const;
    unsigned int numPoints() const;
    void         projectEndpoints();

private:
    std::vector<unsigned int> indices_;
    // Data structures
    CachedData c_data_;
    RangeData r_data_;
    Params params_;
    PointParams p_params_;
    // Point variances used for least squares
    std::vector<double> point_scalar_vars_;
    std::vector<boost::array<double, 4> > point_covs_;
    double p_rr_;
    // Line parameters
    double angle_;
    double radius_;
    boost::array<double, 2> start_;
    boost::array<double, 2> end_;
    boost::array<double, 4> covariance_;
    // Methods
    void    angleFromEndpoints();
    void    angleFromLeastSq();
    double  angleIncrement();
    void    calcCovariance();
    void    calcPointCovariances();
    void    calcPointParameters();
    void    calcPointScalarCovariances();
    void    radiusFromEndpoints();
    void    radiusFromLeastSq();
}; // class Line

class LineExtraction
{

public:
    // Constructor / destructor
    LineExtraction();
    ~LineExtraction();
    // Run
    void extractLines(std::vector<Line>&);
    // Data setting
    void setCachedData(const std::vector<double>&, const std::vector<double>&,
                       const std::vector<double>&, const std::vector<unsigned int>&);
    void setRangeData(const std::vector<double>&);
    // Parameter setting
    void setBearingVariance(double);
    void setRangeVariance(double);
    void setLeastSqAngleThresh(double);
    void setLeastSqRadiusThresh(double);
    void setMaxLineGap(double);
    void setMinLineLength(double);
    void setMinLinePoints(unsigned int);
    void setMinRange(double);
    void setMinSplitDist(double);
    void setOutlierDist(double);

private:
    // Data structures
    CachedData c_data_;
    RangeData r_data_;
    Params params_;
    // Indices after filtering
    std::vector<unsigned int> filtered_indices_;
    // Line data
    std::vector<Line> lines_;
    // Methods
    double chiSquared(const Eigen::Vector2d&, const Eigen::Matrix2d&,
                      const Eigen::Matrix2d&);
    double distBetweenPoints(unsigned int index_1, unsigned int index_2);
    void   filterClosePoints();
    void   filterOutlierPoints();
    void   filterLines();
    void   mergeLines();
    void   split(const std::vector<unsigned int>&);
};

class Scanlineextraction
{
private:
    bool data_cached_; // true after first scan used to cache data
    LineExtraction line_extraction_;
public:
    Scanlineextraction();
    ~Scanlineextraction(){};
    vector<Line> run(const mars_message::LaserScan& scan_msg);
    //获取零度角的墙角度
    bool getzerowallangle(const mars_message::LaserScan& scan_msg,double& angle);

    //获取带偏移零度角的墙角度
    bool getzerowallangle2(const mars_message::LaserScan& scan_msg,double& angle,double inputangle);


    //获取左边90度角的墙的角度和长度
    bool getleft90wallangle(const mars_message::LaserScan& scan_msg,double& angle,double& len);
    //获取右边90度角的墙的角度和长度
    bool getright90wallangle(const mars_message::LaserScan& scan_msg,double& angle,double& len);
    //删除左边墙９０度的雷达数据，返回值代表是否删除了点
    bool deleteleft90wallscanangle(mars_message::LaserScan& scan_msg);
    //删除右边墙９０度的雷达数据，返回值代表是否删除了点
    bool deleteright90wallscanangle(mars_message::LaserScan& scan_msg);

    void loadParameters();
    void cacheData(const mars_message::LaserScan& scan_msg);
};

#endif //SCAN_LINE_EXTRACTION_SCAN_LINE_EXTRACTION_H
