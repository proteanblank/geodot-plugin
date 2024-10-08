#include "LineFeature.h"
#include "gdal-includes.h"

LineFeature::LineFeature(OGRFeature *feature) : Feature(feature) {
    line = feature->GetGeometryRef()->toLineString();
    point_count = line->getNumPoints();
    geometry_type = LINE;
}

LineFeature::LineFeature(OGRFeature *feature, OGRGeometry *linestring) : Feature(feature) {
    line = linestring->toLineString();
    point_count = line->getNumPoints();
    geometry_type = LINE;
}

std::vector<double> LineFeature::get_line_point(int index) {
    return std::vector<double>{line->getX(index), line->getY(index), line->getZ(index)};
}

int LineFeature::get_point_count() {
    return point_count;
}

double LineFeature::get_line_point_x(int index) {
    return line->getX(index);
}

double LineFeature::get_line_point_y(int index) {
    return line->getY(index);
}

double LineFeature::get_line_point_z(int index) {
    return line->getZ(index);
}

void LineFeature::set_point_count(int new_count) {
    line->setNumPoints(new_count);
    point_count = new_count;
}

void LineFeature::set_line_point(int index, double x, double y, double z) {
    line->setPoint(index, x, y, z);
}
