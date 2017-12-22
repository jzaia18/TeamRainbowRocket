public class AI{ //AI class to be used by opposing NPC Pokemon.
    
    public static Move findBestMove(Pokemon user, Pokemon foe){ //Finds the move that does the most damage when used by user. Is blind to some information about the foe.
	Move currBestMove = user._move1; //Assumes 1st Move is the best
	int currBestDamage = BattleUtils.calcDamageAI(user, foe, user._move1);
	int m2dmg = BattleUtils.calcDamageAI(user, foe, user._move2);
	int m3dmg = BattleUtils.calcDamageAI(user, foe, user._move3);
	int m4dmg = BattleUtils.calcDamageAI(user, foe, user._move4);
	if (currBestDamage < m2dmg){ //If 2nd Move does more damage, pick that one
	    currBestDamage = m2dmg;
	    currBestMove = user._move2;
	}
	else if (currBestDamage < m3dmg){ //If 3rd Move does more damage, pick that one
	    currBestDamage = m3dmg;
	    currBestMove = user._move3;
	}
	else if (currBestDamage < m4dmg){ //If 4th Move does more damage, pick that one
	    currBestDamage = m4dmg;
	    currBestMove = user._move4;
	}
	return currBestMove; //Return the strongest Move found
    }    

    public static void useBestMove(Pokemon user, Pokemon foe){
	Move temp = findBestMove(user, foe);
	if (temp.equals(user._move1)) user.move1(foe);
	else if (temp.equals(user._move2)) user.move2(foe);
	else if (temp.equals(user._move3)) user.move3(foe);
	else user.move4(foe);
    }
}


	   
