//
// Description: This is the interface for chatterbot10
//
//
#ifndef __CHATTERBOT10_H__
#define __CHATTERBOT10_H__

#include "strings.h"
#include <iostream>
#include <ctime>
using namespace std;

typedef struct {
	char *keyword[MAX_INP];
	char *response[MAX_RESP];
} record;

typedef struct {
	char *first;
	char *second;
} transpos_t;


class CBot {

public:
	CBot (string str)
		:m_sBotName(str), m_bQuitProgram(0), m_sInput("null") {};
	~CBot () {};

	void get_input();
	void respond();

	void signon();


	bool quit() const {
		return m_bQuitProgram;
	}

private:
	void find_match();
	void handle_repetition();
	void handle_user_repetition();
	void handle_event(string str);


	void select_response();

	void save_prev_input() {
		m_sPrevInput = m_sInput;
	}

	void save_prev_response() {
		m_sPrevResponse = m_sResponse;
	}

	void save_prev_event() {
		m_sPrevEvent = m_sEvent;
	}

	void set_event(string str) {
		m_sEvent = str;
	}

	void save_input() {
		m_sInputBackup = m_sInput;
	}

	void set_input(string str) {
		m_sInput = str;
	}

	void restore_input() {
		m_sInput = m_sInputBackup;
	}

	void print_response() const {
		if(m_sResponse.length() > 0) {
			cout << m_sResponse << endl;
		}
	}

	void preprocess_input();

	void preprocess_response();

	void find_subject();

	bool bot_repeat() const {
		return (m_sPrevResponse.length() > 0 &&
			m_sResponse == m_sPrevResponse);
	}

	bool user_repeat() const;

	bool bot_understand() const {
		return response_list.size() > 0;
	}

	bool null_input() const {
		return (m_sInput.length() == 0 && m_sPrevInput.length() != 0);
	}

	bool null_input_repetition() const {
		return (m_sInput.length() == 0 && m_sPrevInput.length() == 0);
	}

	bool user_want_to_quit() const {
		return m_sInput.find("BYE") != string::npos;
	}

	bool same_event() const {
		return (m_sEvent.length() > 0 && m_sEvent == m_sPrevEvent);
	}

	bool no_response() const {
		return response_list.size() == 0;
	}

	bool same_input() const {
		return (m_sInput.length() > 0  && m_sInput == m_sPrevInput);
	}

	bool wrong_location(string keyword, char firstChar, char lastChar, size_t pos);

	bool similar_input() const;

	void transpose(string &str);

private:
	string	m_sBotName;
	string	m_sUserName;
	string	m_sInput;
	string	m_sResponse;
	string	m_sPrevInput;
	string	m_sPrevResponse;
	string	m_sEvent;
	string	m_sPrevEvent;
	string	m_sInputBackup;
	string	m_sSubject;
	string	m_sKeyWord;
	bool m_bQuitProgram;

	vstring	response_list;

};

#endif
