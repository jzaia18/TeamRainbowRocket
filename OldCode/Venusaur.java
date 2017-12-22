
public class Venusaur extends Pokemon{
    
    public Venusaur(){
	_name = "Venusaur";
	_hp = (int)(Math.random() *48 + 140);
	_atk = (int)(Math.random() *70 + 78);
	_def = (int)(Math.random() *70 + 79);
	_spatk = (int)(Math.random() *74 + 94);
	_spdef = (int)(Math.random() *74 + 94);
	_speed = (int)(Math.random() *70 + 76);
	_currhp = _hp;
	_type1 = "Grass";
	_type2 = "Poison";
	_move1 = new Move("Petal Blizzard", "Grass", 90, 1, true, false, false);
	_move2 = new Move("Earthquake", "Ground", 100, 1, true, false, false);
	_move3 = new Move("Synthesis", "Grass", 50, 1, false, false, true);
	_move4 = new Move("Sludge Bomb", "Poison", 90, 10, false, false, false);
    }

    public String toString(){
	return "\u001B[32m @@@@@@@@@@@@@@@@@@@@@@@@S%.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@@@@@@@?+++++.SS+:%+#+%++:,..+%@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@:++::.......+S%*:::.*.*S++**....+%@@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@.+S::+.?..+:++....+++...::.....+%+*::+++@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@,+SSS*.++++:::..:::%?????#+....++*++++?.*+S.@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@,S@@SS+++SSS+S++%@?%???????@++S++*S++SSSS@+.@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@?SSSSSSSSSS@@%?#%?##?#?@@SS**:SSSSSS+.@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@@@@@@,SSS%.%.?SSSS.....?@+:SSSSSSS,@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@:.+S.SS?.%#?%%%SSS+????S%%%.??.SS.%:@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@%++S+SS.%%.%?????%.%?%.?..%...??%%....?%SS+S+SS%@@@@@@\u001B[0m \n \u001B[32m@@+.++++SS++SSS.S.....*%+SSSS%+SSS?S+....%.SSSSSSS.SSSS+%@@@\u001B[0m \n \u001B[32m*S+++++S?SSSS+SSS?.......SSSSSSSS+SS.+.?.S+S?SS.SSS+S+++#+.S\u001B[0m \n \u001B[32m?,..,+S?SS#S.?%..?+.....??.SS++SSS.%++++++%......???.*+.%+..\u001B[0m \n \u001B[32m@@@@@@@*S..%?SSS...S.......S+...?+++++++++++......SS.,@@@@@@\u001B[0m \n \u001B[32m@@@@@@@S..S%SS.....S@+#+.....+++....%%S@++++S?SSS.S..S.@@@@@\u001B[0m \n \u001B[32m@@@@@@....S++S%SS+............++.......++S?SSSSSS.S....@@@@@\u001B[0m \n \u001B[32m@@@@@@,...SSSSS.S+SS:#%++.....++.++%S%%:.SS..SSSS%SS.%%@@@@@\u001B[0m \n \u001B[32m@@@@@@@@...SSSSSSSS+S%.....+....+......S%SSSSSSSS....%@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@S...SSSSSSSS.S%?.**********S.SS.S..S.SS.%...@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@**?..S.?SSSS%+?........#+S..%....SS.S:::@*@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@@@@.%...S%.@@@@@@@@@@@@%...SS..S...@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@@@@...S:.?:@@@@@@@@@@@@SS.....S..@@@@@@@@@@@@@@@\u001B[0m \n \u001B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.S%,..S:?@@@@@@@@@@@@@@@@\u001B[0m ";
    }
}

	
