/*
  Superclass for all Pokemon.
  Contains:
     -Instance vars for each of its stats and Moves, along with accessors.
     -A takeDamage and heal method.
     -Methods to use each of its 4 Moves.
 */

public class Pokemon{
    
    protected int _hp, _speed, _spatk, _atk, _spdef, _def, _currhp; //6 Basic important stats (hp is 2 of them)
    protected String _type1, _type2; // The elemental typesof the Pokemon (type2 can be Null)
    protected String _name; //The name of the Pokemon (ex: Pikachu, Togepi, etc.)

    // The 4 Moves the Pokemon has access to
    public Move _move1;
    public Move _move2;
    public Move _move3;
    public Move _move4;


    // Methods for chaning the amount of HP a Pokemon has
    public void setCurrHP(int amt){_currhp = amt;}
    public void takeDamage(int d){_currhp -= d;}
    public void heal(double h){
	_currhp += (int)(h/100 * _hp);
	if (_currhp > _hp)
	    _currhp = _hp;
    } 


    //Methods that use a Move specified by the user
    public void move1(Pokemon p){_move1.use(this, p);}
    public void move2(Pokemon p){_move2.use(this, p);}
    public void move3(Pokemon p){_move3.use(this, p);}
    public void move4(Pokemon p){_move4.use(this, p);}

    
    //Accessor methods
    public int getMaxHP(){  //Highest possible HP
	return _hp;}
    public int getCurrHP(){  // Current HP (as an amount, not a percentage)
	return _currhp;}
    public int getSpeed(){
	return _speed;}
    public int getAtk(){
	return _atk;}
    public int getDef(){
	return _def;}
    public int getSpAtk(){
	return _spatk;}
    public int getSpDef(){
	return _spdef;}
    public String getName(){
	return _name;}
    public String getType1(){
	return _type1;}
    public String getType2(){  //May return Null
	return _type2;}
}
