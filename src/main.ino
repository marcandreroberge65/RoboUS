/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

/* ****************************************************************************
Inclure les librairies de functions que vous voulez utiliser
**************************************************************************** */

#include <LibRobus.h> // Essentielle pour utiliser RobUS



/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
int nbtours,nbtoursd;




/* ****************************************************************************
Vos propres fonctions sont creees ici
**************************************************************************** */

void tourner (int x)
{
  if (x>0)
  {
    

    while (x!=0)
    {
    ENCODER_ReadReset(0);
    nbtours= (ENCODER_Read(0));
    MOTOR_SetSpeed(0,0.5);
    
    while ( nbtours < 1995)
        {
        delay(10);
        nbtours=ENCODER_Read(0);
        }
     x--;
    }    
  MOTOR_SetSpeed(0,0);
  } 
    
    
if (x<0)
  {
    

    while (x!=0)
    {
    ENCODER_ReadReset(1);
    nbtours= (ENCODER_Read(1));
    MOTOR_SetSpeed(1,0.5);
    
    while ( nbtours < 1995)
        {
        delay(10);
        nbtours=ENCODER_Read(1);
        }
     x++;
    }    
  MOTOR_SetSpeed(1,0);
  } 
}  


/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales

void setup()
  {BoardInit();}



/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

  void loop() 
{
  if (ROBUS_IsBumper(RIGHT))
  {
    tourner(4);
  }

  else if (ROBUS_IsBumper(LEFT))
  {
    tourner(-4);

  }
}  
  