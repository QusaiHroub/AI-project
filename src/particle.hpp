#ifndef PARTICLE_HPP
#define PARTICLE_HPP


class Particle
{
public:
    Particle();
    Particle(long double, int);
    Particle(const Particle *);
    Particle(const Particle &);

    long double getWeight() const;
    void setWeight(long double);
    int getPosition() const;
    void setPosition(int);
    long double getL() const;
    void setL(long double);
    long double getH() const;
    void setH(long double);

    Particle &operator=(const Particle &);

private:
    const long double MIN_WEIGHT = 1e-20l;
    long double m_weight;
    int m_position;
    
    /// generate and used by MapLevel99Plus.
    long double m_l;
    long double m_h;
};

#endif // PARTICLE_HPP
