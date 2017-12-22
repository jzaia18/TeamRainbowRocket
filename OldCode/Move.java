/*
  A class to be instantiated and carried by each Pokemon.
  Each Pokemon gets 4, and each Move has its own Move stats
*/
public class Move{

    public String _name, _type; //Name and elemental type of the move
    public int _basePow;  //Base power for the Move
    public double _acc;  //Accuracy of the move (0 - 1)
    public Boolean _isPhysical, _makesContact, _heal; //Is the move physical or special? Does it make contact? does it heal?

    public Move(String name, String type, int basePow, double acc, Boolean physical, Boolean contact, boolean heal){//Move creation
	_name = name;
	_type = type;
	_basePow = basePow;
	_acc = acc;
	_isPhysical = physical;
	_makesContact = contact;
	_heal = heal;
    }

    public String toString(){ //For printing Move choices in terminal
	return _name;
    }
    
    public void use(Pokemon user, Pokemon foe){ //Uses the Move, reroutes a bulk of the work to BattleUtils
	if (this._heal)
	    user.heal(this._basePow);	
	else
	    foe.takeDamage(BattleUtils.calcDamage(user, foe, this));
    }

    public boolean equals(Move m){
	return _name.equals(m._name);
    }
}
