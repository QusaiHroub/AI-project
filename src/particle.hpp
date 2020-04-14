#ifndef PARTICLE_HPP
#define PARTICLE_HPP


class Particle
{
public:
    Particle();
    Particle(long double, int);
    Particle(Particle *);

    long double getWeight();
    void setWeight(long double);
    int getPosition();
    void setPosition(int);
    long double getL();
    void setL(long double);
    long double getH();
    void setH(long double);

private:
    const long double MIN_Weight = 1.0l / 1e20;
    long double m_weight;
    int m_position;

    long double m_l;
    long double m_h;
};

#endif // PARTICLE_HPP
