/** @file NbreCplx.h
 *
 * NbreCplx class header
 */

#ifndef TD_INTRO_NBRECPLX_H
#define TD_INTRO_NBRECPLX_H


#include <cmath>

#define D_COORDSYST_DEFAULT COORD_RECTANGULAR /**< default representation system @see coord_system */

/** @enum current representation system
 *
 */
enum coord_system {
    COORD_RECTANGULAR, /**< using rectangular system a+ib */
    COORD_POLAR /**< using polar system r*e^(i*theta) */
};

/** NbreCplx class
 *
 */
class NbreCplx {


public:
    /* ========================= */
    /* constructors & destructor */
    /* ========================= */

    /** default void constructor
     * creates NbreCplx plus
     * - sets rect representation
     * - sets members to 0
     */
    NbreCplx::NbreCplx();

    /** from another NbreCplx object constructor
     *
     * @param from source objects to read values (read only)
     */
    NbreCplx::NbreCplx(const NbreCplx & from);

    /** full setup constructor
     *
     * @param val1 a member in rect representation, module in polar
     * @param val2 b member in rect representation, angle in polar
     * @param representation system to be used for complex representation : @see coord_system defined in class header
     */
    NbreCplx::NbreCplx(float_t val1, float_t val2, coord_system representation=D_COORDSYST_DEFAULT);

    /** standard destructor
     *
     */
    NbreCplx::~NbreCplx();


    /* ================= */
    /* getters & setters */
    /* ================= */

    /** getter rect a
     *
     * @return a member (rectangular)
     */
    float_t getCoord_rect_a() const;

    /** setter rect a
     *
     * @param a member (rectangular)
     */
    void setCoord_rect_a(float_t coord_rect_a);

    /** getter rect b
     *
     * @return b member (rectangular)
     */
    float_t getCoord_rect_b() const;

    /** setter rect b
     *
     * @param b member (rectangular)
     */
    void setCoord_rect_b(float_t coord_rect_b);

    /** getter pol x
     *
     * @return r member (polar)
     */
    float_t getCoord_polr_x() const;

    /** setter pol x
     *
     * @param r member (polar)
     */
    void setCoord_polr_x(float_t coord_polr_x);

    /** getter pol y
     *
     * @return theta member (polar)
     */
    float_t getCoord_polr_y() const;

    /** setter pol y
     *
     * @param theta member (polar)
     */
    void setCoord_polr_y(float_t coord_polr_y);

    /** getter coord system
     *
     * @return current complex representation system
     */
    coord_system getCoord_representation() const;

    /** setter coord system
     *
     * @param coord_representation new system to use for complex representation
     */
    void setCoord_representation(coord_system coord_representation);


private:
    /* ================= */
    /* private functions */
    /* ================= */

    /** copy NbreCplx attributes : objects from->dest
     *
     * @param dest destination object for values
     * @param from source object (read only)
     */
    static void cpCoord(NbreCplx & dest, const NbreCplx & from);

    /** copy values to NbreCplx attributes : floats -> object dest
     *
     * @param dest destination object for values
     * @param val1 either rect_a or pol_module (selected by representation)
     * @param val2 either rect_b or pol_angle (selected by representation)
     * @param representation either rect or pol : @see coord_system
     */
    static void cpCoord(NbreCplx & dest, const float_t & val1, const float_t & val2, const coord_system & representation=D_COORDSYST_DEFAULT);

    /** converts objects to use rectangular system
     *
     */
    void toRectangular();

    /** converts objects to use polar system
     *
     */
    void toPolar();

    /* ================== */
    /* private attributes */
    /* ================== */

    float_t coord_rect_a; /**< real member in rect representation a+ib */

    float_t coord_rect_b; /**< complex member in rect representation a+ib */

    float_t coord_polr_x; /**< module in polar representation */

    float_t coord_polr_y; /**< angle in polar representation */

    coord_system coord_representation; /**< rect/polar system */

};

#endif //TD_INTRO_NBRECPLX_H
