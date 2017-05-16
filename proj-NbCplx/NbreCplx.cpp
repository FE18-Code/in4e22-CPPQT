#include "NbreCplx.h"



/* constructors & destructor */

NbreCplx::NbreCplx() {
    NbreCplx(0, 0, COORD_RECTANGULAR);
}

NbreCplx::NbreCplx(const NbreCplx & from) {
    this->setCoord_representation(from.getCoord_representation());
    NbreCplx::cpCoord(*this, from);

}

NbreCplx::NbreCplx(float_t val1, float_t val2, coord_system representation=D_COORDSYST_DEFAULT) {

    /* first setting up representation */
    this->setCoord_representation(representation);

    /* then filling up values */
    NbreCplx::cpCoord(*this, val1, val2, representation);
}

NbreCplx::~NbreCplx() {
    /* void */
}



/* getters & setters */

float_t NbreCplx::getCoord_rect_a() const {
    return coord_rect_a;
}

void NbreCplx::setCoord_rect_a(float_t coord_rect_a) {
    NbreCplx::coord_rect_a = coord_rect_a;
}

float_t NbreCplx::getCoord_rect_b() const {
    return coord_rect_b;
}

void NbreCplx::setCoord_rect_b(float_t coord_rect_b) {
    NbreCplx::coord_rect_b = coord_rect_b;
}

float_t NbreCplx::getCoord_polr_x() const {
    return coord_polr_x;
}

void NbreCplx::setCoord_polr_x(float_t coord_polr_x) {
    NbreCplx::coord_polr_x = coord_polr_x;
}

float_t NbreCplx::getCoord_polr_y() const {
    return coord_polr_y;
}

void NbreCplx::setCoord_polr_y(float_t coord_polr_y) {
    NbreCplx::coord_polr_y = coord_polr_y;
}

coord_system NbreCplx::getCoord_representation() const {
    return coord_representation;
}

void NbreCplx::setCoord_representation(coord_system coord_representation) {
    if(this->getCoord_representation()!=coord_representation){
        if(coord_representation==COORD_RECTANGULAR){
            this->toRectangular();
        }
        if(coord_representation==COORD_POLAR){
            this->toPolar();
        }
    }/* else : already in coord_representation : nothing to do */
}



/* private functions */

void NbreCplx::toRectangular(){
    float_t a;
    float_t b;

    a=(float_t)acos(this->getCoord_polr_y());
    b=(float_t)asin(this->getCoord_polr_x());

    this->setCoord_rect_a(a);
    this->setCoord_rect_b(b);
    this->setCoord_representation(COORD_RECTANGULAR);
}

void NbreCplx::toPolar(){
    float_t mod;
    float_t ang;

    mod=(float_t)pow(this->getCoord_rect_a(), (double_t)2);
    mod+=(float_t)pow(this->getCoord_rect_b(), (double_t)2);
    ang=(float_t)cos((double_t)this->getCoord_rect_a());

    this->setCoord_polr_x(mod);
    this->setCoord_polr_y(ang);
    this->setCoord_representation(COORD_POLAR);
}

void NbreCplx::cpCoord(NbreCplx & dest, const NbreCplx & from){
    coord_system repr = from.getCoord_representation();

    if(repr == COORD_RECTANGULAR){
        NbreCplx::cpCoord(dest, from.getCoord_rect_a(), from.getCoord_rect_b(), repr);
    }else{ /* polar */
        NbreCplx::cpCoord(dest, from.getCoord_polr_x(), from.getCoord_polr_y(), repr);
    }
}

void NbreCplx::cpCoord(NbreCplx & dest, const float_t & val1, const float_t & val2, const coord_system & representation=D_COORDSYST_DEFAULT){
    dest.setCoord_representation(representation);

    if(dest.getCoord_representation() == COORD_RECTANGULAR){
        dest.setCoord_rect_a(val1);
        dest.setCoord_rect_b(val2);
    }else{ /* polar */
        dest.setCoord_polr_x(val1);
        dest.setCoord_polr_y(val2);
    }
}
