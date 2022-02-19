#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <string>

class imagen
{
    std::vector<int> _pixels;
    int _ancho,_alto;
    public:
        imagen();
        imagen(int ancho,int alto);
        imagen(const imagen& other);

        int getpixel(int i,int j)const{
            return _pixels[i*_ancho+j];
        }

        void setpixel(int i,int j,int valor){
            _pixels[i*_ancho+j] = valor;
        }

        void lee(std::string nombrefichero);
        void escribe(std::string nombrefichero) const;

    protected:

    private:
};

#endif // IMAGEN_H
