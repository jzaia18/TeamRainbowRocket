public class Gengar extends Pokemon{
    public Gengar(){
       	_name = "Gengar";
	_hp = (int)(Math.random() *48 + 120);
	_atk = (int)(Math.random() *66 + 63);
	_def = (int)(Math.random() *66 + 58);
	_spatk = (int)(Math.random() *80 + 121);
	_spdef = (int)(Math.random() *68 + 72);
	_speed = (int)(Math.random() *76 + 103);
	_currhp = _hp;
	_type1 = "Ghost";
	_type2 = "Poison";
	_move1 = new Move("Shadow Ball", "Ghost", 80, 1, false, false, false);
	_move2 = new Move("Sludge Bomb", "Poison", 90, 1, false, false, false);
	_move3 = new Move("Psychic", "Psychic", 90, 1, false, false, false);
	_move4 = new Move("Thunderbolt", "Electric", 90, 1, false, false, false);
    }

    public String toString(){
	return " \u001B[35m@@@@@@@@@@@@S.+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@@@%SS+..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@@@?SS++..+.@@@@,@@@@@@@@@@@@@.#@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@@@.SSS+++++SS#*.S*%.@@@S%....#@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@.@@@@@@@@@SSSSSSSSSSSSSSSSSSS......*@@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@+SSSS...+*@+S+S++......++++..+++SSSSSSSSS+.++++..+++++++S#\u001B[0m \n \u001B[35m@:.+SSSS++++S?SSS..+.......++..+++++SSSSSSSS++++++.++SSSS+@@\u001B[0m \n \u001B[35m@@@@SSSSSSSSSSSS.++.+.........++++++SSSSSSSSS++SSSSSSS?@@@@@\u001B[0m \n \u001B[35m@@@@@@@SSSSSSSSSS:*+.+++++++++++SSSSSSSSSSSSSSSSS.,@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@:SSSSSSSS.**.?S+SS++++SSSSSSSSS.SSSSSSSS?@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@+SSSSSSS?**.?.SSSSSSSS+SSSS+.*SSSSSSS?@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@+SSSSS@.SSS....SSSSSSSSS+.....+SSSSSSS?SSSSSSSS.S?@@@\u001B[0m \n \u001B[35m@@@@@@#++SSSS@@SSSSSSSSSSSSSSS*****..SSSSSSSS.SSSSSSSSSSS.@@\u001B[0m \n \u001B[35m@@@@@@%++SS..:@:::#SSSSSSSSSSS.?S%?SSSSSSSSSSSSSSSSSSSSS+@@@\u001B[0m \n \u001B[35m@@@@@@?SSS....*+:::*S:+?SSSSSSSSSSSSS.SSSSSSSSSSSSSS#@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@%SS......::*%::::::*::::*S**SS..........?@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@%%S...%%%%%%.?,:::::**::::::,%........*@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@#...%%?%%%%%%%%%%%%%%%%SSSSSSSS..%@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@#%%%%#....%%%%%%%%%%.SSSSSSSS...@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@%.?,@@@@?.%%%%%%%.......SSSSSS@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@@@@@@@@@@@?%%..:@.SSSSSSSSSSS?@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@@@@@@@@@@@@@@#,@@@@SS.%.%?.S@@@@@@@@@@@@@@@@@@@@@@\u001B[0m \n \u001B[35m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@S%%%%.#@@@@@@@@@@@@@@@@@@@@@@@\u001B[0m ";
    }
}
