#pragma once

#include <memory>
#include <set>

#include "Math.hpp"
#include "Utils.hpp"

namespace odr
{
class Road;

enum class GeometryType
{
    Line,
    Spiral,
    Arc,
    ParamPoly3
};

struct RoadGeometry
{
    RoadGeometry(double s0, double x0, double y0, double hdg0, double length, GeometryType type);
    virtual ~RoadGeometry();

    virtual void update() = 0;

    virtual Vec2D get_xy(double s) const = 0;
    virtual Vec2D get_grad(double s) const = 0;

    double s0 = 0;
    double x0 = 0;
    double y0 = 0;
    double hdg0 = 0;
    double length = 0;

    GeometryType type;
    Box2D        bounding_box;
};

using ConstRoadGeometrySet = std::set<std::shared_ptr<const RoadGeometry>, SharedPtrCmp<const RoadGeometry, double, &RoadGeometry::s0>>;
using RoadGeometrySet = std::set<std::shared_ptr<RoadGeometry>, SharedPtrCmp<RoadGeometry, double, &RoadGeometry::s0>>;

} // namespace odr
