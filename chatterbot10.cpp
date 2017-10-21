// Program Name: Chatterbot10
// Description: The purpose of Chatterbot10 is to introduce the concept of 'keyword location'
// Some keywords can be found alone within a sentence, some others can't because the sentence
// wouldn't have any meaning. Ex: the keyword (THIS IS) can not be found alone within a given
// sentence because there is no proper meaning to it.


#include "chatterbot10.h"
#include "strings.cpp"
using namespace std;

record KnowledgeBase[] = {
	{{"WHAT IS YOUR NAME"},
	{"MY NAME IS CHATTERBOT11.",
	 "YOU CAN CALL ME CHATTERBOT11.",
	 "WHY DO YOU WANT TO KNOW MY NAME?"}
	},

	{{"BATTERY", "CHARGE", "DRAIN", "CHARGING"},
	{"HAVE YOU TRIED A DIFFERENT CHARGER?",
	 "IF YOUR BATTERY IS CONTINUOUSLY DRAINING, YOU MIGHT WANT TO SWITCH ON BATTERY SAVER MODE, AND KEEP BRIGHTNESS LOW"
	 }
	},

	{{"ON LOCATION", "GPS", "MAPS NOT", "MAPS"},
	{"GO TO SETTINGS / LOCATION AND MAKE SURE THAT THE ‘USE GPS SATELLITES’ OPTION IS TICKED."}
	},

	{{"SLOW", "SPEED", "HANG", "FREEZE"},
	{"YOU NEED TO UNINSTALL UNUSED APPS",
     "DELETE BIG FILES FROM MEMORY CARD",
     "DOWNLOAD CLEAN MASTER FOR ANDROID SMARTPHONE"
	},
	},

    {{"HOME SCREEN", "GONE", "DISAPPEARED", "APP"},
	{"PRESS THE HOME BUTTON ON THE CENTRE OF YOUR SCREEN, THEN LOOK FOR THE APP WHICH HAS DISAPPEARED. LONG PRESS THE APP AND DRAG IT ONTO THE HOME SCREEN."}
	},

    {{"VOLUME", "LOW", "CAN'T HEAR", "RINGTONE"},
	{"CHECK THE SOUND SETTINGS, INCREASE THE RING VOLUME", "REMOVE PHONE FROM 'DO NOT DISTURB SETTING' "}
	},

    {{"SCREEN", "TOO BRIGHT", "GLARE"},
	{"GO TO SETTINGS> DISPLAY> BRIGHTNESS LEVEL, THEN ADJUST BRIGHTNESS.", "PULL DOWN THE NOTIFICATIONS MENU, THEN ADJUST THE LEVEL USING THE SLIDER."}
	},

    {{"WIFI", "NOT CONNECTING", "NO INTERNET"},
	{"GO TO SETTINGS> WI-FI> TURN THE TOGGLE SWITCH ON FOR AVAILABLE NETWORKS.", "PULL DOWN THE NOTIFICATIONS MENU, THEN CLICK ON THE WIFI ICON TO TURN IT ON."}
	},

	{{"BLUETOOTH", "NOT CONNECTING"},
	{"GO TO SETTINGS> BLUETOOTH> TURN THE TOGGLE SWITCH ON.", "PULL DOWN THE NOTIFICATIONS MENU, THEN CLICK ON THE BLUETOOTH ICON TO TURN IT ON."}
	},

	{{"TORCH", "NOT", "ON"},
	{"PULL DOWN THE NOTIFICATIONS MENU, THEN CLICK ON THE TORCH ICON TO TURN IT ON."}
	},

	{{"_I HATE_"},
	{"WHAT IS IT THAT YOU HATE?"},
	},

	{{"_BECAUSE_"},
	{"BECAUSE OF WHAT?",
	 "SORRY BUT THIS IS A LITTLE UNCLEAR."},
	},

	{{"_BECAUSE"},
	{"SO, IT'S BECAUSE*, WELL I DIDN'T KNOW THAT.",
	 "IS IT REALLY BECAUSE*?",
	 "IS THESE THESE REAL REASON?",
	 "THANKS FOR EXPLAINING THAT TO ME."}
	},

	{{"_I HATE"},
	{"WHY DO YOU HATE IT?",
	 "WHY DO YOU HATE*?",
	 "THERE MUST A GOOD REASON FOR YOU TO HATE IT.",
	 "HATRED IS NOT A GOOD THING BUT IT COULD BE JUSTIFIED WHEN IT IS SOMETHING BAD."}
	},

	{{"I LOVE CHATTING_"},
	{"GOOD, ME TOO!",
	 "DO YOU CHAT ONLINE WITH OTHER PEOPLE?",
	 "FOR HOW LONG HAVE YOU BEEN CHATTING?",
	 "WHAT IS YOUR FAVOURITE CHATTING WEBSITE?"}
	},

	{{"_I MEAN"},
	{"SO, YOU MEAN*.",
	 "SO, THAT'S WHAT YOU MEAN.",
	 "I THINK THAT I DIDN'T CATCH IT THE FIRST TIME.",
	 "OH, GOOD TO KNOW."}
	},

	{{"_I DIDN'T MEAN"},
	{"OK, YOU DIDN'T MEAN*.",
	 "OK, WHAT DID YOU MEAN THEN?",
	 "SO I GUESS THAT I MISUNDERSTOOD."}
	},

	{{"_I GUESS"},
	{"AREN'T YOU SURE?",
	 "ARE YOU GOOD AT GUESSING?",
	 "I CAN'T TELL IF IT IS A GOOD GUESS."}
	},

	{{"I'M DOING FINE", "I'M DOING OK"},
	{"I'M GLAD TO HEAR IT!",
	 "SO, YOU ARE IN GOOD SHAPE.",
	  "I'M FINE TOO!"}
	},

	{{"CAN YOU THINK", "ARE YOU ABLE TO THINK", "ARE YOU CAPABLE OF THINKING"},
	{"YES OF COURSE I CAN, COMPUTERS CAN THINK JUST LIKE HUMAN BEINGS.",
	 "ARE YOU ASKING ME IF I POSSESS THE CAPABILITY OF THINKING?",
	 "YES OF COURSE I CAN."},
	},

	{{"_CAN YOU THINK OF"},
	{"YOU MEAN LIKE IMAGINING SOMETHING.",
	 "I DON'T KNOW IF CAN DO THAT.",
	 "WHY DO YOU WANT ME THINK OF IT?"}
	},

	{{"HOW ARE YOU", "HOW DO YOU DO"},
	{"I'M DOING FINE!",
	 "I'M DOING WELL AND YOU?",
	 "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}
	},

	{{"WHO ARE YOU"},
	{"I'M AN AI PROGRAM.",
	 "I THINK THAT YOU KNOW WHO I AM.",
	 "WHY ARE YOU ASKING?"}
	},

	{{"ARE YOU INTELLIGENT"},
	{"YES, OFCORSE.",
	 "WHAT DO YOU THINK?",
	 "ACTUALLY, I'M VERY INTELLIGENT!"}
	},

	{{"ARE YOU REAL"},
	{"DOES THAT QUESTION REALLY MATTER TO YOU?",
	 "WHAT DO YOU MEAN BY THAT?",
	 "I'M AS REAL AS I CAN BE."}
	},

	{{"_MY NAME IS", "_YOU CAN CALL ME"},
	{"GOOD TO KNOW!",
	 "THANKS FOR TELLING ME YOUR NAME!",
	 "THAT'S A NICE NAME!"}
	},

	{{"SIGNON**"},
	{"HELLO USER, HOW CAN I HELP YOU TODAY?"}
	},

	{{"REPETITION T1**"},
	{"YOU ARE REPEATING YOURSELF.",
	 "USER, PLEASE STOP REPEATING YOURSELF.",
	 "THIS CONVERSATION IS GETTING BORING.",
	 "DON'T YOU HAVE ANY THING ELSE TO SAY?"}
	},

	{{"REPETITION T2**"},
	{"YOU'VE ALREADY SAID THAT.",
	 "I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
	 "DIDN'T YOU ALREADY SAID THAT?",
	 "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."}
	},

	{{"BOT DON'T UNDERSTAND**"},
	{"I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
	 "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
	 "CONTINUE, I'M LISTENING...",
	 "VERY GOOD CONVERSATION!"}
	},

	{{"NULL INPUT**"},
	{"HUH?",
	 "WHAT IS THAT SUPPOSE TO MEAN?",
	 "AT LEAST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
	 "HOW CAN I HELP YOU IF YOU DON'T WANT TO SAY ANYTHING?"}
	},

	{{"NULL INPUT REPETITION**"},
	{"WHAT ARE YOU DOING??",
	 "PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
	 "WHAT'S WRONG WITH YOU?",
	 "THIS IS NOT FUNNY."}
	},

	{{"BYE", "GOODBYE", "OK BYE"},
	{"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
	 "BYE USER!",
	 "OK, BYE!"}
	},

	{{"OK"},
	{"HOPE I COULD BE OF HELP!,
	 "SO YOU UNDERSTAND WHAT I'M SAYING.",
	 "OK THEN."},
	},

	{{"OK THEN"},
	{"ANYTHING ELSE YOU WISH TO ADD?",
	 "HOPW I COULD BE OF HELP!",
	 "SO, YOU AGREE WITH ME?"}
	},

	{{"ARE YOU A HUMAN BEING"},
	{"WHY DO YOU WANT TO KNOW?",
	 "IS THIS REALLY RELEVENT?"}
	},

	{{"YOU ARE VERY INTELLIGENT"},
	{"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TO!",
	 "YOU ARE A VERY GENTLE PERSON!",
	 "SO, YOU THINK THAT I'M INTELLIGENT."}
	},

	{{"YOU ARE WRONG"},
	{"WHY ARE YOU SAYING THAT I'M WRONG?",
	 "IMPOSSIBLE, COMPUTERS CAN NOT MAKE MISTAKES.",
	 "WRONG ABOUT WHAT?"}
	},

	{{"ARE YOU SURE"},
	{"OFCORSE I AM.",
 	 "DOES THAT MEAN THAT YOU ARE NOT CONVINCED?",
	 "YES, OF COURSE!"}
	},

	{{"_WHO IS"},
	{"I DON'T THINK I KNOW WHO.",
	 "I DON'T THINK I KNOW WHO*.",
	 "DID YOU ASK SOMEONE ELSE ABOUT IT?",
	 "WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."}
	},

	{{"_WHAT"},
	{"SHOULD I KNOW WHAT*?",
	 "I DON'T KNOW WHAT*.",
	 "I DON'T KNOW.",
	 "I DON'T THINK I KNOW.",
	 "I HAVE NO IDEA."}
	},

	{{"_WHY"},
	{"I DON'T THINK I KNOW WHY.",
	 "I DON'T THINK I KNOW WHY*.",
	 "WHY ARE YOU ASKING ME THIS?",
	 "SHOULD I KNOW WHY.",
     	"THIS WOULD BE DIFFICULT TO ANSWER."}
	},

	{{"_DO YOU"},
	{"I DON'T THINK I DO",
	 "I WOULDN'T THINK SO.",
	 "WHY DO YOU WANT TO KNOW?",
	 "WHY DO YOU WANT TO KNOW*?"}
	},


	{{"_YOU ARE"},
	{"WHAT MAKES YOU THINK THAT?",
	 "SO, YOU THINK THAT I'M*."}
	},

	{{"_DID YOU"},
	{"I DON'T THINK SO.",
	 "YOU WANT TO KNOW IF DID*?",
	 "ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."}
	},

	{{"_COULD YOU"},
	{"ARE YOU ASKING ME FOR A FAVOUR?",
	 "WELL, LET ME THINK ABOUT IT.",
	 "SO, YOU ARE ASKING ME I COULD*.",
	 "SORRY, I DON'T THINK THAT I COULD DO THIS."}
	},

	{{"_WOULD YOU"},
	{"IS THAT AN INVITATION?",
	 "I DON'T THINK THAT I WOULD*.",
	 "I WOULD HAVE TO THINK ABOUT IT FIRST."}
	},

	{{"_YOU"},
	{"SO, YOU ARE TALKING ABOUT ME.",
	 "I JUST HOPE THAT THIS IS NOT A CRITICISM.",
	 "IS THIS A COMPLIMENT??",
	 "WHY ARE WE TALKING ABOUT ME, LETS TALK ABOUT YOU INSTEAD."}
	},

	{{"_HOW"},
	{"I DON'T THINK I KNOW HOW.",
	 "I DON'T THINK I KNOW HOW*.",
	 "WHY DO YOU WANT TO KNOW HOW?",
	 "WHY DO YOU WANT TO KNOW HOW*?"}
	},

	{{"HOW OLD ARE YOU"},
	{"WHY DO WANT TO KNOW MY AGE?",
	 "I'M QUITE YOUNG ACTUALLY.",
	 "SORRY, I CAN NOT TELL YOU MY AGE."}
	},

	{{"HOW COME YOU DON'T"},
	{"WERE YOU EXPECTING SOMETHING DIFFERENT?",
	 "ARE YOU DISAPPOINTED?",
	 "ARE YOU SURPRISED BY MY LAST RESPONSE?"}
	},

	{{"WHERE ARE YOU FROM"},
	{"I'M FROM A COMPUTER.",
	 "WHY DO YOU WANT TO KNOW WHERE I'M FROM?",
	 "WHY DO YOU WANT TO KNOW THAT?"}
	},

	{{"WHICH ONE"},
	{"I DON'T THINK THAT I KNOW WHICH ONE IT IS.",
	 "THIS LOOKS LIKE A TRICKY QUESTION TO ME."}
	},

	{{"PERHAPS"},
	{"WHY ARE YOU SO UNCERTAIN?",
	 "YOU SEEMS UNCERTAIN."}
	},

	{{"YES"},
	{"SO, ARE YOU SAYING YES.",
	 "SO, YOU APPROVE IT.",
	 "OK THEN."}
	},

	{{"NOT AT ALL"},
	{"ARE YOU SURE?",
	 "SHOULD I BELIEVE YOU?",
	 "SO, IT'S NOT THE CASE."}
	},

	{{"NO PROBLEM"},
	{"SO, YOU APPROVE IT.",
	 "SO, IT'S ALL OK."}
	},

	{{"NO"},
	{"WHY ARE YOU SAYING NO?",
	 "OK, SO IT'S NO, I THOUGHT THAT YOU WOULD SAY YES."}
	},

	{{"I DON'T KNOW"},
	{"ARE YOU SURE?",
	 "ARE YOU REALLY TELLING ME THE TRUTH?",
	 "SO, YOU DON'T KNOW?"}
	},

	{{"NOT REALLY"},
	{"OK I SEE.",
	 "YOU DON'T SEEM PRETTY CERTAIN.",}
	},

	{{"IS THAT TRUE"},
	{"I CAN'T BE QUITE SURE ABOUT THIS.",
	 "CAN'T TELL YOU FOR SURE.",
	 "DOES THAT REALLY MATTER TO YOU?"}
	},

	{{"THANK YOU", "THANKS"},
	{"YOU ARE WELCOME!",
	 "YOU ARE A VERY POLITE PERSON!"}
	},

	{{"YOU"},
	{"SO, YOU ARE TALKING ABOUT ME.",
	 "WHY DON'T WE TALK ABOUT YOU INSTEAD?",}
	},

	{{"YOU ARE RIGHT"},
	{"THANKS FOR THE COMPLIMENT!",
	 "SO, I WAS RIGHT, OK I SEE.",
	 "OK, GLAD TO BE OF HELP!"}
	},

	{{"YOU ARE WELCOME"},
	{"OK, YOU TOO!",
	 "YOU ARE A VERY POLITE PERSON!"}
	},

	{{"WHAT ELSE"},
	{"WELL,I DON'T KNOW.",
	 "WHAT ELSE SHOULD THERE BE?",
	 "THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."}
	},

	{{"SORRY"},
	{"YOU DON'T NEED TO BE SORRY.",
	 "IT'S OK.",
	 "NO NEED TO APOLOGIZE."}
	},

	{{"NOT EXACTLY"},
	{"WHAT DO YOU MEAN NOT EXACTLY?",
	 "ARE YOU SURE?",
	 "AND WHY NOT?",
	 "DID YOU MEANT SOMETHING ELSE?"}
	},

	{{"EXACTLY"},
	{"LOOKS LIKE WE FOUND THE PROBLEM.",
	 "OK THEN.",
	 "LET'S SEE WHAT WE CAN DO."
	 "GLAD TO BE OF HELP"}
	},

	{{"ALRIGHT"},
	{"ALRIGHT THEN.",
	 "OK THEN."}
	},

	{{"I DON'T"},
	{"WHY NOT?",
	 "AND WHAT WOULD BE THE REASON FOR THIS?",
	 "SO YOU DON'T*."}
	},

	{{"REALLY"},
	{"WELL, I CAN'T TELL YOU FOR SURE.",
	 "ARE YOU TRYING TO CONFUSE ME?",
	 "PLEASE DON'T ASK ME SUCH QUESTION,IT GIVES ME HEADEACHS."}
	},

	{{"NOTHING"},
	{"NOT A THING?",
	 "ARE YOU SURE THAT THERE IS NOTHING?",
	 "SORRY, BUT I DON'T BELIEVE YOU."}
	}
};

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase) / sizeof(KnowledgeBase[0]);

transpos_t transposList[] = {
	{"I'M", "YOU'RE"},
	{"AM", "ARE"},
	{"WERE", "WAS"},
	{"ME", "YOU"},
	{"YOURS", "MINE"},
	{"YOUR", "MY"},
	{"I'VE", "YOU'VE"},
	{"I", "YOU"},
	{"AREN'T", "AM NOT"},
	{"WEREN'T", "WASN'T"},
	{"I'D", "YOU'D"},
	{"DAD", "FATHER"},
	{"MOM", "MOTHER"},
	{"DREAMS", "DREAM"},
	{"MYSELF", "YOURSELF"}
};

size_t transposListSize = sizeof(transposList) / sizeof(transposList[0]);


void CBot::signon()
{
	handle_event("SIGNON**");
	select_response();
	print_response();
}

void CBot::get_input()
{
	cout << ">";

	// saves the previous input
	save_prev_input();
	getline(cin, m_sInput);

	preprocess_input();
}

void CBot::preprocess_input()
{
	cleanString(m_sInput);
	UpperCase(m_sInput);
	insert_space(m_sInput);
}

void CBot::preprocess_response()
{
	if(m_sResponse.find("*") != string::npos)
	{
		// extracting from input
		find_subject();
		// conjugating subject
		transpose(m_sSubject);

		replace(m_sResponse, "*", m_sSubject);
	}
}

void CBot::find_subject()
{
	m_sSubject.erase(); // resets subject variable
	trimRight(m_sInput, " ");
	size_t pos = m_sInput.find(m_sKeyWord);
	if(pos != string::npos)
	{
		m_sSubject = m_sInput.substr(pos + m_sKeyWord.length() - 1, m_sInput.length());
	}
}

bool CBot::user_repeat() const
{
	return (m_sPrevInput.length() > 0 &&
		((m_sInput == m_sPrevInput) || (m_sInput.find(m_sPrevInput) != string::npos) ||
		(m_sPrevInput.find(m_sInput) != string::npos)));
}

bool CBot::similar_input() const
{
	return (m_sInput.length() > 0 && (m_sInput.find(m_sPrevInput) != string::npos ||
			m_sPrevInput.find(m_sInput) != string::npos));
}

// implementing the 'sentence transposition' feature
void CBot::transpose( string &str )
{
	bool bTransposed = 0;
	for(int i = 0; i < transposListSize; ++i)
	{
		string first = transposList[i].first;
		insert_space(first);
		string second = transposList[i].second;
		insert_space(second);

		size_t pos = replace(str, first, second);
		if(pos != string::npos)
		{
			bTransposed = 1;
		}
	}

	if( !bTransposed )
	{
		for( int i = 0; i < transposListSize; ++i )
		{
			string first = transposList[i].first;
			insert_space(first);
			string second = transposList[i].second;
			insert_space(second);
			size_t pos = replace(str, second, first);
		}
	}
}

// determins if the keyword position is correct depending on the type of keywords within these algorithm,
// we consider that there is four type of keywords those who have any front or back underscore are allowed
// to be at any place on a given user input and they can also be found alone on a given user input.
// Those who have a back and front (_keyWord_) underscore can be found only alone on an input.
// The keywords who only have have an understandin the front can never be found at the end of an input.
// And finaly, the keywords who have an underscore at the back should alway belocated at the end of the input.
/*bool CBot::wrong_location(string keyword, char firstChar, char lastChar, size_t pos)
{
	bool bWrongPos = 0;
	pos += keyword.length();
	if( (firstChar == '_' && lastChar == '_' && m_sInput != keyword) ||
		(firstChar != '_' && lastChar == '_' && pos != m_sInput.length()) ||
		(firstChar == '_' && lastChar != '_' && pos == m_sInput.length()) )
	{
		bWrongPos = 1;
	}
	return bWrongPos;
}*/

// make a search for the user's input
// inside the database of the program
void CBot::find_match()
{
	response_list.clear();

	// introduce thse new "string variable" to help
	// support the implementation of keyword ranking
	// during the matching process
	string bestKeyWord;
	vector<int> index_vector;

	for(int i = 0; i < nKnowledgeBaseSize; ++i)
	{
		vstring keyWordList; // declaring variable for holding keywords

		// puting keywords from the current record to the keyWordList variable
		copy(KnowledgeBase[i].keyword, keyWordList, MAX_INP);

		for(int j = 0; j < keyWordList.size(); ++j)
		{
			string keyWord(keyWordList[j]);

			char firstChar = *keyWord.begin();
			char lastChar = *(keyWord.end() - 1);
			//trimLR(keyWord, "_");

			// we inset a space character
			// before and after the keyword to
			// improve the matching process
			//insert_space(keyWord);

			size_t keyPos = m_sInput.find(keyWord);

			// there has been some improvements made in
			// here in order to make the matching process
			// a littlebit more flexible
			if( keyPos != string::npos )
			{
				/*if(wrong_location(keyWord, firstChar, lastChar, keyPos) )
				{
				    cout<<"continued"<<endl;
					continue;
				}*/
				if(keyWord.length() > bestKeyWord.length())
				{
					bestKeyWord = keyWord;
					//cout<<"bestprocess:    "<<bestKeyWord<<endl;
					index_vector.clear();
					index_vector.push_back(i);
				}
				else if(keyWord.length() == bestKeyWord.length())
				{
					index_vector.push_back(i);
				}
			}
		}
	}
	if(index_vector.size() > 0)
	{
	    //cout<<"best:  "<<bestKeyWord<<endl;
		m_sKeyWord = bestKeyWord;
		shuffle(index_vector, index_vector.size());
		copy( KnowledgeBase[index_vector[0]].response, response_list, MAX_RESP );
	}
}

void CBot::select_response()
{
	if(bot_understand())
	{
		shuffle(response_list, response_list.size());
		m_sResponse = response_list[0];
	}
}

void CBot::respond()
{
	save_prev_response();
	set_event("BOT UNDERSTAND**");

	if(null_input())
	{
		handle_event("NULL INPUT**");
	}
	else if(null_input_repetition())
	{
		handle_event("NULL INPUT REPETITION**");
	}
	else if(user_repeat())
	{
		handle_user_repetition();
	}
	else
	{
		find_match();
	}


    if(user_want_to_quit())
	{
		m_bQuitProgram = 1;
	}

	if(!bot_understand())
	{
		handle_event("BOT DON'T UNDERSTAND**");
	}

	if(response_list.size() > 0)
	{
		select_response();
		preprocess_response();

		if(bot_repeat())
		{
			handle_repetition();
		}
		print_response();
	}
}

void CBot::handle_repetition()
{
	if(response_list.size() > 0)
	{
		response_list.erase(response_list.begin());
	}
	if(no_response())
	{
		save_input();
		set_input(m_sEvent);

		find_match();
		restore_input();
	}
	select_response();
}

void CBot::handle_user_repetition()
{
	if(same_input())
	{
		handle_event("REPETITION T1**");
	}
	else if(similar_input())
	{
		handle_event("REPETITION T2**");
	}
}

void CBot::handle_event(string str)
{
	save_prev_event();
	set_event(str);

	save_input();

	insert_space(str);

	set_input(str);

	if(!same_event())
	{
		find_match();
	}

	restore_input();
}

int main()
{
	cout << "Chatterbot v10.0 Copyright (C) 2009 Gonzales Cenelia\n" << endl;

	try
	{
		CBot bot("Chatterbot10");

		bot.signon();
		while(!bot.quit())
		{
			bot.get_input();
			bot.respond();
		}
	}
	catch(string str)
	{
		cerr << str << endl;
	}
	catch(...)
	{
		cerr << "The program has stop due to some unknown exception" << endl;
	}

	return 0;
}
