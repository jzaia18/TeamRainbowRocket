public static float computeEffectiveness(String atktype, String deftype1, String deftype2){
  //Where atktype is the type of the Move being used,
  //   deftypes are the types of the Pokemon the Move is being used on.

  float effectiveness = 1;
  if (deftype2 == null) //if the deftype is null it causes runtime errors, this is a simple fix
    deftype2 = "None";

  //Following is a giant list that checks every possible attacktype against all deftypes.

  if (atktype.equals("Electric")) 
    {
      if  (deftype1.equals("Electric") || deftype2.equals("Electric")) effectiveness *= 0.5;
      if  (deftype1.equals("Grass") || deftype2.equals("Grass"))       effectiveness *= 0.5;
      if  (deftype1.equals("Water") || deftype2.equals("Water"))       effectiveness *= 2;
      if  (deftype1.equals("Flying") || deftype2.equals("Flying"))     effectiveness *= 2;
      if  (deftype1.equals("Ground") || deftype2.equals("Ground"))     effectiveness *= 0;
      if  (deftype1.equals("Dragon") || deftype2.equals("Dragon"))     effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype.equals("Grass"))
    {
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))     effectiveness *= .5;
      if (deftype1.equals("Poison") || deftype2.equals("Poison"))   effectiveness *= .5;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))       effectiveness *= .5;
      if (deftype1.equals("Water") || deftype2.equals("Water"))     effectiveness *= 2;
      if (deftype1.equals("Bug") || deftype2.equals("Bug"))         effectiveness *= .5;
      if (deftype1.equals("Flying") || deftype2.equals("Flying"))   effectiveness *= .5;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))       effectiveness *= 2;
      if (deftype1.equals("Ground") || deftype2.equals("Ground"))   effectiveness *= 2;
      if (deftype1.equals("Dragon") || deftype2.equals("Dragon"))   effectiveness *= .5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))     effectiveness *= .5;
      return effectiveness;
    }
  if (atktype.equals("Poison"))
    {
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))   effectiveness *= 2;
      if (deftype1.equals("Poison") || deftype2.equals("Poison")) effectiveness *= 0.5;
      if (deftype1.equals("Ghost") || deftype2.equals("Ghost"))   effectiveness *= 0.5;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))     effectiveness *= 0.5;
      if (deftype1.equals("Ground") || deftype2.equals("Ground")) effectiveness *= 0.5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))   effectiveness *= 0;
      return effectiveness;
    }
  if (atktype.equals("Fire"))
    {
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))   effectiveness *= 2;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))     effectiveness *= 0.5;
      if (deftype1.equals("Water") || deftype2.equals("Water"))   effectiveness *= 0.5;
      if (deftype1.equals("Bug") || deftype2.equals("Bug"))       effectiveness *= 2;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))     effectiveness *= 0.5;
      if (deftype1.equals("Dragon") || deftype2.equals("Dragon")) effectiveness *= 0.5;
      if (deftype1.equals("Ice") || deftype2.equals("Ice"))       effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))   effectiveness *= 2;
      return effectiveness;
    }
  if (atktype.equals("Water"))
    {
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))   effectiveness *= 0.5;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))     effectiveness *= 2;
      if (deftype1.equals("Water") || deftype2.equals("Water"))   effectiveness *= 0.5;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))     effectiveness *= 2;
      if (deftype1.equals("Ground") || deftype2.equals("Ground")) effectiveness *= 2;
      if (deftype1.equals("Dragon") || deftype2.equals("Dragon")) effectiveness *= 0.5;
      return effectiveness; }
  if (atktype.equals("Bug"))
    {
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))       effectiveness *= 2;
      if (deftype1.equals("Poison") || deftype2.equals("Poison"))     effectiveness *= 0.5;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))         effectiveness *= 0.5;
      if (deftype1.equals("Flying") || deftype2.equals("Flying"))     effectiveness *= 0.5;
      if (deftype1.equals("Ghost") || deftype2.equals("Ghost"))       effectiveness *= 0.5;
      if (deftype1.equals("Fighting") || deftype2.equals("Fighting")) effectiveness *= 0.5;
      if (deftype1.equals("Psychic") || deftype2.equals("Psychic"))   effectiveness *= 2;
      if (deftype1.equals("Dark") || deftype2.equals("Dark"))         effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 0.5;
      return effectiveness; }
  if (atktype.equals("Flying"))
    {
      if (deftype1.equals("Electric") || deftype2.equals("Electric")) effectiveness *= 0.5;
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))       effectiveness *= 2;
      if (deftype1.equals("Bug") || deftype2.equals("Bug"))           effectiveness *= 2;
      if (deftype1.equals("Fighting") || deftype2.equals("Fighting")) effectiveness *= 2;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))         effectiveness *= 0.5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 0.5;
      return effectiveness; }
  if (atktype.equals("Normal"))
    {
      if (deftype1.equals("Ghost") || deftype2.equals("Ghost")) effectiveness *= 0;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))   effectiveness *= 0.5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel")) effectiveness *= 0.5;
      return effectiveness; }
  if (atktype.equals("Ghost"))
    {
      if (deftype1.equals("Normal") || deftype2.equals("Normal"))   effectiveness *= 0;
      if (deftype1.equals("Ghost") || deftype2.equals("Ghost"))     effectiveness *= 2;
      if (deftype1.equals("Psychic") || deftype2.equals("Psychic")) effectiveness *= 2;
      if (deftype1.equals("Dark") || deftype2.equals("Dark"))       effectiveness *= 0.5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))     effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype.equals("Fighting"))
    {
      if (deftype1.equals("Poison") || deftype2.equals("Poison"))   effectiveness *= 0.5;
      if (deftype1.equals("Bug") || deftype2.equals("Bug"))         effectiveness *= 0.5;
      if (deftype1.equals("Flying") || deftype2.equals("Flying"))   effectiveness *= 0.5;
      if (deftype1.equals("Normal") || deftype2.equals("Normal"))   effectiveness *= 2;
      if (deftype1.equals("Ghost") || deftype2.equals("Ghost"))     effectiveness *= 0;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))       effectiveness *= 2;
      if (deftype1.equals("Psychic") || deftype2.equals("Psychic")) effectiveness *= 0.5;
      if (deftype1.equals("Dark") || deftype2.equals("Dark"))       effectiveness *= 2;
      if (deftype1.equals("Ice") || deftype2.equals("Ice"))         effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))     effectiveness *= 2;
      return effectiveness;
    }
  if (atktype.equals("Rock"))
    {
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))         effectiveness *= 2;
      if (deftype1.equals("Bug") || deftype2.equals("Bug"))           effectiveness *= 2;
      if (deftype1.equals("Flying") || deftype2.equals("Flying"))     effectiveness *= 2;
      if (deftype1.equals("Fighting") || deftype2.equals("Fighting")) effectiveness *= 0.5;
      if (deftype1.equals("Ground") || deftype2.equals("Ground"))     effectiveness *= 0.5;
      if (deftype1.equals("Ice") || deftype2.equals("Ice"))           effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype.equals("Ground"))
    {
      if (deftype1.equals("Electric") || deftype2.equals("Electric")) effectiveness *= 2;
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))       effectiveness *= 0.5;
      if (deftype1.equals("Poison") || deftype2.equals("Poison"))     effectiveness *= 2;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))         effectiveness *= 2;
      if (deftype1.equals("Bug") || deftype2.equals("Bug"))           effectiveness *= 0.5;
      if (deftype1.equals("Flying") || deftype2.equals("Flying"))     effectiveness *= 0;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))         effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 2;
      return effectiveness;
    }
  if (atktype.equals("Psychic"))
    {
      if (deftype1.equals("Poison") || deftype2.equals("Poison"))     effectiveness *= 2;
      if (deftype1.equals("Fighting") || deftype2.equals("Fighting")) effectiveness *= 2;
      if (deftype1.equals("Psychic") || deftype2.equals("Psychic"))   effectiveness *= 0.5;
      if (deftype1.equals("Dark") || deftype2.equals("Dark"))         effectiveness *= 0;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 0.5;
      return effectiveness; }
  if (atktype.equals("Dragon"))
    {
      if (deftype1.equals("Dragon") || deftype2.equals("Dragon")) effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))   effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype.equals("Dark"))
    {
      if (deftype1.equals("Ghost") || deftype2.equals("Ghost"))       effectiveness *= 2;
      if (deftype1.equals("Fighting") || deftype2.equals("Fighting")) effectiveness *= 0.5;
      if (deftype1.equals("Psychic") || deftype2.equals("Psychic"))   effectiveness *= 2;
      if (deftype1.equals("Dark") || deftype2.equals("Dark"))         effectiveness *= 0.5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype.equals("Ice"))
    {
      if (deftype1.equals("Grass") || deftype2.equals("Grass"))   effectiveness *= 2;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))     effectiveness *= 0.5;
      if (deftype1.equals("Water") || deftype2.equals("Water"))   effectiveness *= 0.5;
      if (deftype1.equals("Flying") || deftype2.equals("Flying")) effectiveness *= 2;
      if (deftype1.equals("Ground") || deftype2.equals("Ground")) effectiveness *= 2;
      if (deftype1.equals("Dragon") || deftype2.equals("Dragon")) effectiveness *= 2;
      if (deftype1.equals("Ice") || deftype2.equals("Ice"))       effectiveness *= 0.5;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))   effectiveness *= 0.5;
      return effectiveness;
    }
  if (atktype.equals("Steel"))
    {
      if (deftype1.equals("Electric") || deftype2.equals("Electric")) effectiveness *= 0.5;
      if (deftype1.equals("Fire") || deftype2.equals("Fire"))         effectiveness *= 0.5;
      if (deftype1.equals("Water") || deftype2.equals("Water"))       effectiveness *= 0.5;
      if (deftype1.equals("Rock") || deftype2.equals("Rock"))         effectiveness *= 2;
      if (deftype1.equals("Ice") || deftype2.equals("Ice"))           effectiveness *= 2;
      if (deftype1.equals("Steel") || deftype2.equals("Steel"))       effectiveness *= 0.5;
      return effectiveness;
    }
  return effectiveness; //Should never be reached in practice, but is needed for getting past the compiler
}


//----------------------------------------REAL CALCULATIONS ----------------------------------------------------------------

public static double calcModifier(Pokemon attacker, Pokemon defender, Move m){
	//Calculates all modifiers that are attached to the attacks damage

	double mod = (.15 * Math.random() + .85); //Random element of the attacks damage
	if (m._type == attacker.getType1() || m._type == attacker.getType2()) //Same Type Attack Bonus (STAB)
    mod *= 1.5;
	if (Math.random() * 16 < 1) //Did the attack Crit?
    mod *= 1.5;
	float effectiveness = computeEffectiveness(m._type, defender.getType1(), defender.getType2()); //Finds the type effectiveness (see method above)
	if (effectiveness > 1.0f)
    System.out.println("It's super effective!");   //Displays type effectiveness in terminal
	else if (effectiveness == 0.0f)
    System.out.println("But it had no effect...");
	else if (effectiveness < 1.0f)
    System.out.println("It's not very effective.");	    
	mod *= effectiveness;
	return mod; //Return the combined modifier
}

public static int calcDamage(Pokemon attacker, Pokemon defender, Move m){
	if (Math.random() > m._acc){ //Accuracy check
    System.out.println("But it missed.");
    return 0;}
	else {
    double mod = calcModifier(attacker, defender, m); //Finds the modifiers on the attack (see above method)
    if (m._isPhysical)
      return (int) (mod * (.44 * attacker.getAtk() / defender.getDef() * m._basePow + 2)); //Calculations for physical damage
    else
      return (int) (mod * (.44 * attacker.getSpAtk() / defender.getSpDef() * m._basePow + 2)); //Calculations for physical damage
	}
}





//-----------------------------CALCULATIONS FOR AI DECISIONS----------------------------------------------------------------

//Similar to the methods for real calculations, except it neglects some information, in order to make a more balanced AI
    
public static double calcModifierAI(Pokemon attacker, Pokemon defender, Move m){ //Does not factor in random damage fluctuations, or crit
	double mod = 1;
	if (m._type == attacker.getType1() || m._type == attacker.getType2())
    mod *= 1.5;
	mod *= computeEffectiveness(m._type, defender.getType1(), defender.getType2());
	return mod;	
}
    
public static int calcDamageAI(Pokemon attacker, Pokemon defender, Move m){ //Does not factor in the defenders defensive strength
	double mod = calcModifierAI(attacker, defender, m);
	if (m._isPhysical)
    return (int) (mod * (.44 * attacker.getAtk() * m._basePow + 2));
	else
    return (int) (mod * (.44 * attacker.getSpAtk() * m._basePow + 2));
}

}

