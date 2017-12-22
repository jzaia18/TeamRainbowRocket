public class Snorlax extends Pokemon{

    public Snorlax(){
       	_name = "Snorlax";
	_hp = (int)(Math.random() *48 + 220);
	_atk = (int)(Math.random() *76 + 103);
	_def = (int)(Math.random() *66 + 63);
	_spatk = (int)(Math.random() *66 + 63);
	_spdef = (int)(Math.random() *76 + 103);
	_speed = (int)(Math.random() *60 + 31);
	_currhp = _hp;
	_type1 = "Normal";
	_move1 = new Move("Earthquake", "Ground", 100, 1, true, false, false);
	_move2 = new Move("Crunch", "Dark", 80, 1, true, true, false);
	_move3 = new Move("Body Slam", "Normal", 85, 1, true, true, false);
	_move4 = new Move("Zen Headbutt", "Psychic", 80, .9, true, true, false);
    }

    public String toString(){
	return " @@@@@@@@@@@@@@@@@@@@@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n @@@@@@@@@@@@@@@@@@@@@.SSS..@@:..:@@@@,.SSS:@@@@@@@@@@@@@@@@@ \n @@@@@@@@@@@@@@@@@@@@@SSSSSSS++SSSSSSSSSSS..@@@@@@@@@@@@@@@@@ \n @@@@@@@@@@@@@@@@@@@@*SSSSSSSSSSSSSSSSSSSS%?@@@@@@@@@@@@@@@@@ \n @@@@@@@@@@@@@@@@@@@,+SSS*,SSSSSSS,%SSSSS%%:@@@@@@@@@@@@@@@@@ \n @@@@@@@@@@@@@@@@@.+++.,,,,,:..S,,,,::*.%%%%%%?@@@@@@@@@@@@@@ \n @@@@@@@@@@@@@S+++SS+:,,,,,,:::::::,::**+%%%%%%%%S%@@@@@@@@@@ \n @@@@@@@@@@.+++++SSS%,:%,:,,::::::::*****?%%%%%%SSSSS@@@@@@@@ \n @@@@@@@@%++S+++SSSSS?:::::::::**********%?%%%%SSSSSSSS@@@@@@ \n @@@@@@S.SSSSSSSSS....%+%***.****S******.%%...SSSSSSSSSSS@@@@ \n @@@@@?...........#%,,::*****.S...+***....*.......SSSSSSSS%@@ \n @@@@S........?..S:,,::,::::::*****:::::::::,+.%............@ \n @@@@@,.@.@....?::::::,:::,:,,,::::,:,:::,:::,,....?........? \n @@@@@@@@@@%..?,:::::::,,:::,:,::,:,::::,::,,,::.....%@@:S.++ \n @@@@@@@@@+%%%,::::::::,,:::,:::,:,:,,:,:::,:::::...%%?@@@@@@ \n @@@@@@@@@?%%::::::,,:,:,::::::,,,:,,,,::,,::,,,,%%%%%%@@@@@@ \n @@@@,%@@S,.%***:::::,,,,::::::::,::::::,,:::::::,?%%%,.@@@@@ \n @@@,*.::,S+:+.*******:::::::,,,,:::::::::::****%**.::**%@@.@ \n @:.:::::::::***....**********************..**%::::::::::%*:@ \n @.::.++++.:****+.......**....****..........*%*::::::::::::,@ \n @@*:++++SS.****.%?***..............*.......?****?S++++%::,@@ \n @@@:*......%***#%%%%%#S.*.......**.....?%%%%+**.......S**@@@ \n @@@@@@.******.@@@@@@@@@@@@@@@@@@@@@@@@@@@,@@@S**......*S@@@@ ";
    }
}
