/*
 * CQSParser.cpp
 *
 *  Created on: Oct 8, 2009
 *      Author: Administrator
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const char soh_ = '\x01';
const char eot_ = '\x03';
const char us_ = '\x1F';
int count_ = 0;

void usage(char** argv)
{
    printf("\n			USAGE :");
    printf(" %s <inputfilename> <outputfilename>\n\n",argv[0]);
    return;
}

void substr( char * destination, const char * source, int offset, int size ) {
	int i = 0, idx = 0;
	for(i = offset; i < offset + size - 1; i++) {
		destination[idx++] = source[i];
	}
	destination[size - 1] = '\0';
}

double tradePriceConverter(char* tp, char denominator, int fs) {
	double divisor = 0.0, prefix = 0.0, suffix = 0.0;
	double tmp = atof(tp);
	switch(denominator) {
	case '3':
		divisor = 8.0;
		if(fs == 8) {
			char q1[8];
			char q2[2];
			q2[0] = tp[7];
			q2[1] = '\0';
			substr(q1,tp,0,8);
			prefix = atof(q1);
			suffix = atof(q2);
		} else if(fs == 12) {
			char q1[12];
			char q2[2];
			q2[0] = tp[11];
			q2[1] = '\0';
			substr(q1,tp,0,12);
                        prefix = atof(q1);
                        suffix = atof(q2);
		}
		return (prefix + (suffix/divisor));
		break;
	case '4':
		divisor = 16.0;
                if(fs == 8) {
                        char q1[7];
                        char q2[3];
                        substr(q1,tp,0,7);
                        substr(q2,tp,6,3);
                        prefix = atof(q1);
                        suffix = atof(q2);
                } else if(fs == 12) {
                        char q1[11];
                        char q2[3];
                        substr(q1,tp,0,11);
                        substr(q2,tp,10,3);
                        prefix = atof(q1);
                        suffix = atof(q2);
                }
                return (prefix + (suffix/divisor));
		break;
	case '5':
		divisor = 32.0;
                if(fs == 8) {
                        char q1[7];
                        char q2[3];
                        substr(q1,tp,0,7);
                        substr(q2,tp,6,3);
                        prefix = atof(q1);
                        suffix = atof(q2);
                } else if(fs == 12) {
                        char q1[11];
                        char q2[3];
                        substr(q1,tp,0,11);
                        substr(q2,tp,10,3);
                        prefix = atof(q1);
                        suffix = atof(q2);
                }
                return (prefix + (suffix/divisor));
		break;
	case '6':
		divisor = 64.0;
                if(fs == 8) {
                        char q1[7];
                        char q2[3];
                        substr(q1,tp,0,7);
                        substr(q2,tp,6,3);
                        prefix = atof(q1);
                        suffix = atof(q2);
                } else if(fs == 12) {
                        char q1[11];
                        char q2[3];
                        substr(q1,tp,0,11);
                        substr(q2,tp,10,3);
                        prefix = atof(q1);
                        suffix = atof(q2);
                }
                return (prefix + (suffix/divisor));
		break;
	case '7':
		divisor = 128.0;
                if(fs == 8) {
                        char q1[6];
                        char q2[4];
                        substr(q1,tp,0,6);
                        substr(q2,tp,5,4);
                        prefix = atof(q1);
                        suffix = atof(q2);
                } else if(fs == 12) {
                        char q1[11];
                        char q2[4];
                        substr(q1,tp,0,10);
                        substr(q2,tp,9,4);
                        prefix = atof(q1);
                        suffix = atof(q2);
                }
                return (prefix + (suffix/divisor));
		break;
	case '8':
		divisor = 256.0;
                divisor = 128.0;
                if(fs == 8) {
                        char q1[6];
                        char q2[4];
                        substr(q1,tp,0,6);
                        substr(q2,tp,5,4);
                        prefix = atof(q1);
                        suffix = atof(q2);
                } else if(fs == 12) {
                        char q1[11];
                        char q2[4];
                        substr(q1,tp,0,10);
                        substr(q2,tp,9,4);
                        prefix = atof(q1);
                        suffix = atof(q2);
                }
                return (prefix + (suffix/divisor));
		break;
	case 'A':
		divisor = 10.0;
		return (tmp / divisor);
		break;
	case 'B':
		divisor = 100.0;
		return (tmp / divisor);
		break;
	case 'C':
		divisor = 1000.0;
		return (tmp / divisor);
		break;
	case 'D':
		divisor = 10000.0;
		return (tmp / divisor);
		break;
	case 'E':
		divisor = 100000.0;
		return (tmp / divisor);
		break;
	case 'F':
		divisor = 1000000.0;
		return (tmp / divisor);
		break;
	case 'G':
		divisor = 10000000.0;
		return (tmp / divisor);
		break;
	case 'H':
		divisor = 100000000.0;
		return (tmp / divisor);
		break;
	default:
		divisor = 1.0;
		return (tmp / divisor);
		break;
	}
}

string timeCharMap(char ch) {
	string retv;
	switch(ch) {
	case '0':
		retv = "00";
		break;
	case '1':
		retv = "01";
		break;
	case '2':
		retv = "02";
		break;
	case '3':
		retv = "03";
		break;
	case '4':
		retv = "04";
		break;
	case '5':
		retv = "05";
		break;
	case '6':
		retv = "06";
		break;
	case '7':
		retv = "07";
		break;
	case '8':
		retv = "08";
		break;
	case '9':
		retv = "09";
		break;
	case ':':
		retv = "10";
		break;
	case ';':
		retv = "11";
		break;
	case '<':
		retv = "12";
		break;
	case '=':
		retv = "13";
		break;
	case '>':
		retv = "14";
		break;
	case '?':
		retv = "15";
		break;
	case '@':
		retv = "16";
		break;
	case 'A':
		retv = "17";
		break;
	case 'B':
		retv = "18";
		break;
	case 'C':
		retv = "19";
		break;
	case 'D':
		retv = "20";
		break;
	case 'E':
		retv = "21";
		break;
	case 'F':
		retv = "22";
		break;
	case 'G':
		retv = "23";
		break;
	case 'H':
		retv = "24";
		break;
	case 'I':
		retv = "25";
		break;
	case 'J':
		retv = "26";
		break;
	case 'K':
		retv = "27";
		break;
	case 'L':
		retv = "28";
		break;
	case 'M':
		retv = "29";
		break;
	case 'N':
		retv = "30";
		break;
	case 'O':
		retv = "31";
		break;
	case 'P':
		retv = "32";
		break;
	case 'Q':
		retv = "33";
		break;
	case 'R':
		retv = "34";
		break;
	case 'S':
		retv = "35";
		break;
	case 'T':
		retv = "36";
		break;
	case 'U':
		retv = "37";
		break;
	case 'V':
		retv = "38";
		break;
	case 'W':
		retv = "39";
		break;
	case 'X':
		retv = "40";
		break;
	case 'Y':
		retv = "41";
		break;
	case 'Z':
		retv = "42";
		break;
	case '[':
		retv = "43";
		break;
	case '\\':
		retv = "44";
		break;
	case ']':
		retv = "45";
		break;
	case '^':
		retv = "46";
		break;
	case '_':
		retv = "47";
		break;
	case '`':
		retv = "48";
		break;
	case 'a':
		retv = "49";
		break;
	case 'b':
		retv = "50";
		break;
	case 'c':
		retv = "51";
		break;
	case 'd':
		retv = "52";
		break;
	case 'e':
		retv = "53";
		break;
	case 'f':
		retv = "54";
		break;
	case 'g':
		retv = "55";
		break;
	case 'h':
		retv = "56";
		break;
	case 'i':
		retv = "57";
		break;
	case 'j':
		retv = "58";
		break;
	case 'k':
		retv = "59";
		break;
	default:
		retv = "--";
		break;
	}
	return retv;
}

void parseMsg(char* msgBuf, int msgSize) {
	int i = 0, usStartIdx = 0;
	bool isEquity = false;
	bool isTrade = false;
	char ch;
	char seqNum[10];
	char exch;

	switch (msgBuf[1]) {
		case 'E':
			isEquity = true;
			break;
		default:
			break;
	}
	if(isEquity) {
		switch(msgBuf[2]) {
			case 'B':
				isTrade = true;
				break;
			case 'I':
				isTrade = true;
				break;
			case 'P':
				isTrade = true;
				break;
			case 'Q':
				isTrade = true;
				break;
			default:
				break;
		}
	}
	if(isTrade) {
		usStartIdx = 1;
		count_++;
		/*
		cout << "Msg,";
		for(i = 0; i <= msgSize; i++) {
			cout << msgBuf[i];
		}
		cout << ";" << endl;
		*/
		for(i = 1; i <= msgSize; i++) {
			ch = msgBuf[i];
			/*
			if(ch == us_ || ch == eot_) {
				int tmpS = i - usStartIdx;
				char oneTrade[tmpS];
				//memset(oneTrade,'\0',tmpS);
				k = 0;
				int taken = 0;
				for(j = usStartIdx; j < i; j++) {
					//cout << k << "," << j << "," << msgBuf[j] << endl;
					oneTrade[k] = msgBuf[j];
					k++;
					taken++;
				}
				cout << "Sta," << i << "," << usStartIdx << ",size," << tmpS << ",taken," << taken << endl;
				cout << "Trd,," << oneTrade << ";" << endl;
				j = 0;
				k = 0;
				usStartIdx = i + 1;
			}
			*/
			// found a sub message
			if(ch == us_ || ch == eot_) {
				char millisec[4];
				millisec[0] = msgBuf[usStartIdx + 21];
				millisec[1] = msgBuf[usStartIdx + 22];
				millisec[2] = msgBuf[usStartIdx + 23];
				millisec[3] = '\0';
				char hour = msgBuf[usStartIdx + 18];
				char min = msgBuf[usStartIdx + 19];
				char sec = msgBuf[usStartIdx + 20];
				string hh = timeCharMap(hour);
				string mm = timeCharMap(min);
				string ss = timeCharMap(sec);
				substr(seqNum,msgBuf,usStartIdx + 8, 10);
				exch = msgBuf[usStartIdx + 17];

				// process long trades
				if(msgBuf[usStartIdx] == 'E' && msgBuf[usStartIdx + 1] == 'B') {
					char symbol[12];
					char priceDenom;
					char price[13];
					char size[10];
					char saleCond[5];
					priceDenom = msgBuf[usStartIdx + 56];
					substr(symbol,msgBuf,usStartIdx + 24,12);
					substr(price,msgBuf,usStartIdx + 57,13);
					substr(size,msgBuf,usStartIdx + 69,10);
					substr(saleCond,msgBuf,usStartIdx + 49,5);
					double pp = tradePriceConverter(price,priceDenom,12);
					double sz = atof(size);
					cout << hh << mm << ss << "." << millisec << ",longtrade,"
					<< exch << "," << seqNum << "," << symbol << "," << price << ","
					<< size << "," << saleCond << "," << priceDenom << ","
					<< pp << "," << sz
					<< endl;
				// trade status
				} else if(msgBuf[usStartIdx] == 'E' && msgBuf[usStartIdx + 1] == 'F') {
					int tmp = 1;
					cerr << tmp << endl;
				// short trades
				} else if(msgBuf[usStartIdx] == 'E' && msgBuf[usStartIdx + 1] == 'I') {
					char symbol[4];
					char priceDenom;
					char price[9];
					char size[5];
					char saleCond;
					saleCond = msgBuf[usStartIdx + 27];
					priceDenom = msgBuf[usStartIdx + 32];
					substr(symbol,msgBuf,usStartIdx + 24,4);
					substr(price,msgBuf,usStartIdx + 33,9);
					substr(size,msgBuf,usStartIdx + 28,5);
					double pp = tradePriceConverter(price,priceDenom,8);
					double sz = atof(size);
					cout << hh << mm << ss << "." << millisec << ",shorttrade,"
					<< exch << "," << seqNum << "," << symbol << "," << price << ","
					<< size << "," << saleCond << "," << priceDenom << ","
					<< pp << "," << sz
					<< endl;
				// corrections
				} else if(msgBuf[usStartIdx] == 'E' && msgBuf[usStartIdx + 1] == 'P') {
					char origSeqNum[10];
					char origSymbol[12];
					//char origSaleCond[5];
					char origPriceDenom;
					char origPrice[13];
					char origSize[10];
					char newSaleCond[5];
					char newPriceDenom;
					char newPrice[13];
					char newSize[10];
					origPriceDenom = msgBuf[usStartIdx + 65];
					substr(origSymbol,msgBuf,usStartIdx + 31, 12);
					substr(origSeqNum,msgBuf,usStartIdx + 48, 10);
					substr(origPrice,msgBuf,usStartIdx + 66, 13);
					substr(origSize,msgBuf,usStartIdx + 78, 10);
					newPriceDenom = msgBuf[usStartIdx + 105];
					substr(newSaleCond,msgBuf,usStartIdx + 101, 5);
					substr(newPrice,msgBuf,usStartIdx + 106, 13);
					substr(newSize,msgBuf,usStartIdx + 118, 10);
					cout << hh << mm << ss << "." << millisec << ",correction,"
					<< exch << "," << seqNum << "," << origSeqNum << "," << origSymbol << ","
					<< origPriceDenom << "," << origPrice << "," << origSize << ",corrected,"
					<< newPriceDenom << "," << newPrice << "," << newSize << endl;
				// cancels
				} else if(msgBuf[usStartIdx] == 'E' && msgBuf[usStartIdx + 1] == 'Q') {
					char origSeqNum[10];
					char origSymbol[12];
					//char origSaleCond[5];
					char origPriceDenom;
					char origPrice[13];
					char origSize[10];
					origPriceDenom = msgBuf[usStartIdx + 65];
					substr(origSymbol,msgBuf,usStartIdx + 31, 12);
					substr(origSeqNum,msgBuf,usStartIdx + 49, 10);
					substr(origPrice,msgBuf,usStartIdx + 66, 13);
					substr(origSize,msgBuf,usStartIdx + 78, 10);
					cout << hh << mm << ss << "." << millisec << ",cancel,"
					<< exch << "," << seqNum << "," << origSeqNum << "," << origSymbol << ","
					<< origPriceDenom << "," << origPrice << "," << origSize << endl;
				}
				// process short trades
				usStartIdx = i + 1;
			}
		}
	}
//	if(count_ == 100) {
//		exit(-1);
//	}
}



void parseBlock(char* blockBuf, int msgSize) {
	int i = 0, j = 0, k = 0;
	int tMsgStartIdx = 0;
	int tMsgEndIdx = 0;
	bool tMsgStart = false;
	bool tMsgEnd = false;
	//bool tMsgUS = false;
	cout << "NewMsgSize: " << msgSize << endl;
	for(i = 0; i <= msgSize; i++) {
		if(blockBuf[i] == soh_) {
			tMsgStart = true;
			tMsgStartIdx = i;
		} else if(blockBuf[i] == eot_) {
			tMsgEnd = true;
			tMsgEndIdx = i;
		}
		if(tMsgStartIdx > 0 && tMsgEndIdx > 0 && tMsgEndIdx > tMsgStartIdx) {
			int msgSize = tMsgEndIdx - tMsgStartIdx;
			k = 0;
			char* tmpBuf = new char[msgSize + 1];
			for(j = tMsgStartIdx; j <= tMsgEndIdx; j++) {
				tmpBuf[k] = blockBuf[j];
				k++;
			}
			parseMsg(tmpBuf,msgSize);
			tMsgEndIdx = 0;
			tMsgStartIdx = 0;
			delete [] tmpBuf;
		}
	}
}

int main(int argc, char** argv)
{
	char* infile = {'\0'};
	//char* outfile = {'\0'};
	int bufSize = 524288;
	int i = 0;
	char readBuf[bufSize];
	//char* carryOverBuf;
	char ch;
	cout << "soh," << soh_ << ",eot," << eot_ << ",us," << us_ << endl;
	//int tMsgStartIdx = 0;
	//nt tMsgEndIdx = 0;
	ifstream rawStream;
	//bool tMsgStart = false;
	//bool tMsgEnd = false;
	//bool tMsgUS = false;
	if(argc < 2)
	{
		usage(argv);
		return -1;
	}
	infile = argv[1];
	//outfile = argv[2];
	cout << "infile," << infile << endl;
	rawStream.open(infile,ios::in);

	if(rawStream.bad()) {
		cout << infile << " is bad!" << endl;
		exit(-1);
	}
	/*
	while (!rawStream.eof()) {
		if(rawStream.read(readBuf,bufSize)) {
			for(i = 0; i < bufSize; i++) {
				//cout << readBuf[i];
				if(readBuf[i] == soh) {
					tMsgStart = true;
					tMsgStartIdx = i;
				} else if(readBuf[i] == eot) {
					tMsgEnd = true;
					tMsgEndIdx = i;
				}
				if(tMsgStartIdx > 0 && tMsgEndIdx > 0 && tMsgEndIdx > tMsgStartIdx) {
					int msgSize = tMsgEndIdx - tMsgStartIdx;
					k = 0;
					char* msgBuf = new char[msgSize + 1];
					for(j = tMsgStartIdx; j <= tMsgEndIdx; j++) {
						msgBuf[k] = readBuf[j];
						k++;
					}
					cout << "NewStart," << tMsgStartIdx << ",end," << tMsgEndIdx
					<< ",size," << msgSize << endl;
					parseMsg(msgBuf,msgSize + 1);
					cout << endl;
					tMsgEndIdx = 0;
					tMsgStartIdx = 0;
					delete [] msgBuf;
				}
			}
		} else {
			cout << "Last read..." << endl;
		}
		cout << "Gcount," << rawStream.gcount() << endl;
		memset(&readBuf, 0, sizeof(readBuf));
	}
	*/
	while(rawStream) {
		rawStream.get(ch);
		readBuf[i] = ch;
		i++;
		if(i > 520000 && ch == eot_) {
			parseBlock(readBuf,i);
			memset(&readBuf, 0, sizeof(readBuf));
			i = 0;
		}
	}
	// process the last set
	if(i > 1000) {
		parseBlock(readBuf,i);
	}
    rawStream.close();

	return 0;
}
