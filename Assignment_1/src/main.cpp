////////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <complex>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
////////////////////////////////////////////////////////////////////////////////

const std::string root_path = DATA_DIR;

typedef std::complex<double> Point;
typedef std::vector<Point> Polygon;

double inline det(const Point &u, const Point &v)
{
    // TODO
    return 0;
}

// Return true iff [a,b] intersects [c,d], and store the intersection in ans
bool intersect_segment(const Point &a, const Point &b, const Point &c, const Point &d, Point &ans)
{
    // TODO
    return true;
}

////////////////////////////////////////////////////////////////////////////////

bool is_inside(const Polygon &poly, const Point &query)
{
    // 1. Compute bounding box and set coordinate of a point outside the polygon
    // TODO
    Point outside(0, 0);
    // 2. Cast a ray from the query point to the 'outside' point, count number of intersections
    // TODO
    return true;
}

////////////////////////////////////////////////////////////////////////////////

struct Compare
{
    Point p0; // Leftmost point of the poly
    bool operator()(const Point &p1, const Point &p2)
    {
        // TODO
        return true;
    }
};

bool inline salientAngle(Point &a, Point &b, Point &c)
{
    // TODO
    return false;
}

Polygon convex_hull(std::vector<Point> &points)
{
    Compare order;
    // TODO
    order.p0 = Point(0, 0);
    std::sort(points.begin(), points.end(), order);
    Polygon hull;
    // TODO
    // use salientAngle(a, b, c) here
    return hull;
}

////////////////////////////////////////////////////////////////////////////////

std::vector<Point> load_xyz(const std::string &filename)
{
    std::vector<Point> points;
    std::ifstream in(filename);
    // TODO
    return points;
}

void save_xyz(const std::string &filename, const std::vector<Point> &points)
{
    // TODO
}

Polygon load_obj(const std::string &filename)
{
    std::ifstream in(filename);
    // TODO
    return {};
}

void save_obj(const std::string &filename, Polygon &poly)
{
    std::ofstream out(filename);
    if (!out.is_open())
    {
        throw std::runtime_error("failed to open file " + filename);
    }
    out << std::fixed;
    for (const auto &v : poly)
    {
        out << "v " << v.real() << ' ' << v.imag() << " 0\n";
    }
    for (size_t i = 0; i < poly.size(); ++i)
    {
        out << "l " << i + 1 << ' ' << 1 + (i + 1) % poly.size() << "\n";
    }
    out << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    const std::string points_path = root_path + "/points.xyz";
    const std::string poly_path = root_path + "/polygon.obj";

    std::vector<Point> points = load_xyz(points_path);

    ////////////////////////////////////////////////////////////////////////////////
    //Point in polygon
    Polygon poly = load_obj(poly_path);
    std::vector<Point> result;
    for (size_t i = 0; i < points.size(); ++i)
    {
        if (is_inside(poly, points[i]))
        {
            result.push_back(points[i]);
        }
    }
    save_xyz("output.xyz", result);

    ////////////////////////////////////////////////////////////////////////////////
    //Convex hull
    Polygon hull = convex_hull(points);
    save_obj("output.obj", hull);

    return 0;
}
