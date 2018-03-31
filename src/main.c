

#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

#include "pnm.h"
#include "effets-photom.h"
#include "effets-geom.h"
#include "filtrages.h"

/*!
 \file main.c
 \author
 \date
 \brief programme principal : test des fonctionnalités de manipulation d'image
 */


int main(int argc, char **argv)
{
    int xsize, /*! largeur de l'image */
    ysize;     /*! hauteur de l'image */
    PnmFile fich; /*! "fichier" image : nom, type, taille, bitmap */
    PnmFile fich2; /*! "fichier" image : nom, type, taille, bitmap */
    unsigned char * res=NULL;
    
    if (argc<3) {
        fprintf(stderr,"usage : %s fichier.p[b|g|p]m\n fichier.p[b|g|p]m\n",argv[0]);
        exit(1);
    }
    srand(time(NULL)); /* initialisation du générateur pseudo-aléatoire */
    
    fich.name=argv[1];
    lirefich(&fich);
    fprintf(stderr,"Lecture OK (H=%d L=%d)\n",fich.ysize,fich.xsize);
    xsize=fich.xsize;
    ysize=fich.ysize;
    if ((fich.type!=2)&&(fich.type!=5)) exit(1);
    
    res = inversion_videoNB(fich.bitmap, xsize, ysize);
    
    fich2.bitmap=res;
    fich2.xsize=xsize;
    fich2.ysize=ysize;
    fich2.maxvalue=255;
    fich2.name=argv[2];
    fich2.type=5;
    sauverfich(&fich2);
    
    return 0;
}
