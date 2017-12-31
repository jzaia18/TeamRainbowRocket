#include "sharedheader.h"


// THIS FILE IS UNFINISHED!!!


// MUST BE UPDATED TO GEN 6
float compute_effectiveness(char atktype, char deftype1, char deftype2) {
  // Where atktype is the type of the Move being used, and
  //   deftypes are the types of the Pokemon the Move is being used on.

  float effectiveness = 1;

  //Following is a giant list that checks every possible attacktype against all deftypes.

  if (atktype == ELECTRIC_TYPENO)
    {
      if  (deftype1 == ELECTRIC_TYPENO || deftype2 == ELECTRIC_TYPENO) effectiveness *= 0.5;
      if  (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)       effectiveness *= 0.5;
      if  (deftype1 == WATER_TYPENO || deftype2 == WATER_TYPENO)       effectiveness *= 2;
      if  (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO)     effectiveness *= 2;
      if  (deftype1 == GROUND_TYPENO || deftype2 == GROUND_TYPENO)     effectiveness *= 0;
      if  (deftype1 == DRAGON_TYPENO || deftype2 == DRAGON_TYPENO)     effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype == GRASS_TYPENO)
    {
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)     effectiveness *= .5;
      if (deftype1 == POISON_TYPENO || deftype2 == POISON_TYPENO)   effectiveness *= .5;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)       effectiveness *= .5;
      if (deftype1 == WATER_TYPENO || deftype2 == WATER_TYPENO)     effectiveness *= 2;
      if (deftype1 == BUG_TYPENO || deftype2 == BUG_TYPENO)         effectiveness *= .5;
      if (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO)   effectiveness *= .5;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)       effectiveness *= 2;
      if (deftype1 == GROUND_TYPENO || deftype2 == GROUND_TYPENO)   effectiveness *= 2;
      if (deftype1 == DRAGON_TYPENO || deftype2 == DRAGON_TYPENO)   effectiveness *= .5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)     effectiveness *= .5;
      return effectiveness;
    }
  if (atktype == POISON_TYPENO)
    {
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)   effectiveness *= 2;
      if (deftype1 == POISON_TYPENO || deftype2 == POISON_TYPENO) effectiveness *= 0.5;
      if (deftype1 == GHOST_TYPENO || deftype2 == GHOST_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == GROUND_TYPENO || deftype2 == GROUND_TYPENO) effectiveness *= 0.5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)   effectiveness *= 0;
      return effectiveness;
    }
  if (atktype == FIRE_TYPENO)
    {
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)   effectiveness *= 2;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == WATER_TYPENO || deftype2 == WATER_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == BUG_TYPENO || deftype2 == BUG_TYPENO)       effectiveness *= 2;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == DRAGON_TYPENO || deftype2 == DRAGON_TYPENO) effectiveness *= 0.5;
      if (deftype1 == ICE_TYPENO || deftype2 == ICE_TYPENO)       effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)   effectiveness *= 2;
      return effectiveness;
    }
  if (atktype == WATER_TYPENO)
    {
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)     effectiveness *= 2;
      if (deftype1 == WATER_TYPENO || deftype2 == WATER_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)     effectiveness *= 2;
      if (deftype1 == GROUND_TYPENO || deftype2 == GROUND_TYPENO) effectiveness *= 2;
      if (deftype1 == DRAGON_TYPENO || deftype2 == DRAGON_TYPENO) effectiveness *= 0.5;
      return effectiveness; }
  if (atktype == BUG_TYPENO)
    {
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)       effectiveness *= 2;
      if (deftype1 == POISON_TYPENO || deftype2 == POISON_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)         effectiveness *= 0.5;
      if (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == GHOST_TYPENO || deftype2 == GHOST_TYPENO)       effectiveness *= 0.5;
      if (deftype1 == FIGHTING_TYPENO || deftype2 == FIGHTING_TYPENO) effectiveness *= 0.5;
      if (deftype1 == PSYCHIC_TYPENO || deftype2 == PSYCHIC_TYPENO)   effectiveness *= 2;
      if (deftype1 == DARK_TYPENO || deftype2 == DARK_TYPENO)         effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 0.5;
      return effectiveness; }
  if (atktype == FLYING_TYPENO)
    {
      if (deftype1 == ELECTRIC_TYPENO || deftype2 == ELECTRIC_TYPENO) effectiveness *= 0.5;
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)       effectiveness *= 2;
      if (deftype1 == BUG_TYPENO || deftype2 == BUG_TYPENO)           effectiveness *= 2;
      if (deftype1 == FIGHTING_TYPENO || deftype2 == FIGHTING_TYPENO) effectiveness *= 2;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)         effectiveness *= 0.5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 0.5;
      return effectiveness; }
  if (atktype == NORMAL_TYPENO)
    {
      if (deftype1 == GHOST_TYPENO || deftype2 == GHOST_TYPENO) effectiveness *= 0;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO) effectiveness *= 0.5;
      return effectiveness; }
  if (atktype == GHOST_TYPENO)
    {
      if (deftype1 == NORMAL_TYPENO || deftype2 == NORMAL_TYPENO)   effectiveness *= 0;
      if (deftype1 == GHOST_TYPENO || deftype2 == GHOST_TYPENO)     effectiveness *= 2;
      if (deftype1 == PSYCHIC_TYPENO || deftype2 == PSYCHIC_TYPENO) effectiveness *= 2;
      if (deftype1 == DARK_TYPENO || deftype2 == DARK_TYPENO)       effectiveness *= 0.5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)     effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype == FIGHTING_TYPENO)
    {
      if (deftype1 == POISON_TYPENO || deftype2 == POISON_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == BUG_TYPENO || deftype2 == BUG_TYPENO)         effectiveness *= 0.5;
      if (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == NORMAL_TYPENO || deftype2 == NORMAL_TYPENO)   effectiveness *= 2;
      if (deftype1 == GHOST_TYPENO || deftype2 == GHOST_TYPENO)     effectiveness *= 0;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)       effectiveness *= 2;
      if (deftype1 == PSYCHIC_TYPENO || deftype2 == PSYCHIC_TYPENO) effectiveness *= 0.5;
      if (deftype1 == DARK_TYPENO || deftype2 == DARK_TYPENO)       effectiveness *= 2;
      if (deftype1 == ICE_TYPENO || deftype2 == ICE_TYPENO)         effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)     effectiveness *= 2;
      return effectiveness;
    }
  if (atktype == ROCK_TYPENO)
    {
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)         effectiveness *= 2;
      if (deftype1 == BUG_TYPENO || deftype2 == BUG_TYPENO)           effectiveness *= 2;
      if (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO)     effectiveness *= 2;
      if (deftype1 == FIGHTING_TYPENO || deftype2 == FIGHTING_TYPENO) effectiveness *= 0.5;
      if (deftype1 == GROUND_TYPENO || deftype2 == GROUND_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == ICE_TYPENO || deftype2 == ICE_TYPENO)           effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype == GROUND_TYPENO)
    {
      if (deftype1 == ELECTRIC_TYPENO || deftype2 == ELECTRIC_TYPENO) effectiveness *= 2;
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)       effectiveness *= 0.5;
      if (deftype1 == POISON_TYPENO || deftype2 == POISON_TYPENO)     effectiveness *= 2;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)         effectiveness *= 2;
      if (deftype1 == BUG_TYPENO || deftype2 == BUG_TYPENO)           effectiveness *= 0.5;
      if (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO)     effectiveness *= 0;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)         effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 2;
      return effectiveness;
    }
  if (atktype == PSYCHIC_TYPENO)
    {
      if (deftype1 == POISON_TYPENO || deftype2 == POISON_TYPENO)     effectiveness *= 2;
      if (deftype1 == FIGHTING_TYPENO || deftype2 == FIGHTING_TYPENO) effectiveness *= 2;
      if (deftype1 == PSYCHIC_TYPENO || deftype2 == PSYCHIC_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == DARK_TYPENO || deftype2 == DARK_TYPENO)         effectiveness *= 0;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 0.5;
      return effectiveness; }
  if (atktype == DRAGON_TYPENO)
    {
      if (deftype1 == DRAGON_TYPENO || deftype2 == DRAGON_TYPENO) effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)   effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype == DARK_TYPENO)
    {
      if (deftype1 == GHOST_TYPENO || deftype2 == GHOST_TYPENO)       effectiveness *= 2;
      if (deftype1 == FIGHTING_TYPENO || deftype2 == FIGHTING_TYPENO) effectiveness *= 0.5;
      if (deftype1 == PSYCHIC_TYPENO || deftype2 == PSYCHIC_TYPENO)   effectiveness *= 2;
      if (deftype1 == DARK_TYPENO || deftype2 == DARK_TYPENO)         effectiveness *= 0.5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype == ICE_TYPENO)
    {
      if (deftype1 == GRASS_TYPENO || deftype2 == GRASS_TYPENO)   effectiveness *= 2;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)     effectiveness *= 0.5;
      if (deftype1 == WATER_TYPENO || deftype2 == WATER_TYPENO)   effectiveness *= 0.5;
      if (deftype1 == FLYING_TYPENO || deftype2 == FLYING_TYPENO) effectiveness *= 2;
      if (deftype1 == GROUND_TYPENO || deftype2 == GROUND_TYPENO) effectiveness *= 2;
      if (deftype1 == DRAGON_TYPENO || deftype2 == DRAGON_TYPENO) effectiveness *= 2;
      if (deftype1 == ICE_TYPENO || deftype2 == ICE_TYPENO)       effectiveness *= 0.5;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)   effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype == STEEL_TYPENO)
    {
      if (deftype1 == ELECTRIC_TYPENO || deftype2 == ELECTRIC_TYPENO) effectiveness *= 0.5;
      if (deftype1 == FIRE_TYPENO || deftype2 == FIRE_TYPENO)         effectiveness *= 0.5;
      if (deftype1 == WATER_TYPENO || deftype2 == WATER_TYPENO)       effectiveness *= 0.5;
      if (deftype1 == ROCK_TYPENO || deftype2 == ROCK_TYPENO)         effectiveness *= 2;
      if (deftype1 == ICE_TYPENO || deftype2 == ICE_TYPENO)           effectiveness *= 2;
      if (deftype1 == STEEL_TYPENO || deftype2 == STEEL_TYPENO)       effectiveness *= 0.5;
      return effectiveness;
    }

  return effectiveness; //Should never be reached in practice, but is needed for getting past the compiler
}


//----------------------------------------REAL CALCULATIONS ----------------------------------------------------------------

double compute_modifier(struct Pokemon attacker, struct Pokemon defender, struct Move m){
	//Calculates all modifiers that are attached to the attacks damage

	double mod = .15 * rand2() + .85; //Random element of the attacks damage
	if (m.type == attacker.type1 || m.type == attacker.type2) //Same Type Attack Bonus (STAB)
    mod *= 1.5;
	if (rand2() * 16 < 1) //Did the attack Crit?
    mod *= 1.5;
	float effectiveness = compute_effectiveness(m.type, defender.type1, defender.type2); //Finds the type effectiveness (see method above)
	if (effectiveness > 1.0f)
    printf("It's super effective!\n");   //Displays type effectiveness in terminal
	else if (effectiveness == 0.0f)
    printf("But it had no effect...\n");
	else if (effectiveness < 1.0f)
    printf("It's not very effective.\n");
	mod *= effectiveness;
	return mod; //Return the combined modifier
}

int compute_damage(struct Pokemon attacker, struct Pokemon defender, struct Move m){
	if (rand2() > m.acc){ //Accuracy check
    printf("But it missed.\n");
    return 0;}
	else {
    double mod = compute_modifier(attacker, defender, m); //Finds the modifiers on the attack (see above method)
    if (m.isphysical)
      return (int) (mod * (.44 * attacker.atk / defender.def * m.power + 2)); //Calculations for physical damage
    else
      return (int) (mod * (.44 * attacker.spatk / defender.spdef * m.power + 2)); //Calculations for physical damage
	}
}
