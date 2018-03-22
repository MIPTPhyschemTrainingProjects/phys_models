//
// Created by aleksei on 22.03.18.
//

#ifndef PHYS_MODELS_VECTOR_HPP
#define PHYS_MODELS_VECTOR_HPP


class Vector {
private:
    double _x, _y, _z, _norm;

public:

    /**
     * Creates vector from 3 doubles
     * @param x coordinate
     * @param y coordinate
     * @param z coordinate
     */
    Vector(double x, double y, double z) noexcept;

    /**
     * Creates vector from <i>std::array</t>
     * @param vec -- std::array to be converted to <b>Vector</b>
     */
    Vector(const std::array<double, 3> &vec) noexcept;

    /**
     * Creates vector from pointer that can produce 3 doubles by moving via pointer arithmetic.
     * The pointer should has next three positions free, and these positions should contain `double` values.
     * @param coords Pointer that has 3 doubles in it
     */
    Vector(const double* coords);

    Vector();

    /**
     *
     * @return E2-norm of <b>vector</b>
     */
    double getNorm() const noexcept;

    /**
     *
     * @return x coordinate
     */
    double getX() const noexcept;

    /**
     *
     * @return y coordinate
     */
    double getY() const noexcept;

    /**
     *
     * @return z coordinate
     */
    double getZ() const noexcept;

    /**
     * Convert <b>Vector</b> to std::array
     * @return std::array<double, 3> with coordinates
     */
    std::array<double, 3> toArray() const noexcept;

    Vector operator+(const Vector &other) const noexcept;
    Vector operator-(const Vector &other) const noexcept;
    double operator*(const Vector &other) const noexcept;
    Vector operator^(const Vector &other) const noexcept;
    Vector operator*(double k) const noexcept;
    bool operator==(const Vector &other) const noexcept;
    bool operator!=(const Vector &other) const noexcept;
    Vector operator+=(const Vector &other) noexcept;
    Vector operator-=(const Vector &other) noexcept;
    Vector operator*=(double k) noexcept;
};

Vector operator*(double k, const Vector &v) noexcept;


#endif //PHYS_MODELS_VECTOR_HPP
