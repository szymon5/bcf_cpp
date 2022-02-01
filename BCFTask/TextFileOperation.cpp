#include <iostream>
#include <fstream>
#include <filesystem>
#include <omp.h>

using namespace std;
namespace fs = filesystem;

class TextFileOperation
{
private:
	ifstream file;
	string dir;
	string text_path;

public:

	TextFileOperation(string dir, string txt_file)
	{
		this->dir = dir;
		this->text_path = txt_file;
	}

	int files_counter_in_directory()
	{
		int files_counter = 0;
		string pathfile = dir;

		fs::path p{ pathfile };
		if (fs::exists(p))
		{
			if (fs::is_directory(p))
			{
				for (auto& e : fs::recursive_directory_iterator(p))
				{
					files_counter++;
				}
			}
		}
		else
		{
			cout << "Directory " << p << " does not exist." << endl;
		}

		return files_counter;
	}

	int lines_counter_in_txt_file()
	{
		int cnt = 0;
		string line;
		ifstream file(text_path);

		while (getline(file, line)) cnt++;

		return cnt;
	}

	int words_counter_in_txt_file()
	{
		ifstream file;
		file.open(text_path);
		char word[3000];
		int cnt = 0;
		while (!file.eof())
		{
			file >> word;
			cnt++;
		}

		file.close();

		return cnt;
	}

	int letters_counter_in_txt_file()
	{
		string line;
		ifstream file(text_path);
		int cnt = 0;

		if (file.is_open())
		{

			while (getline(file, line))
			{
				cnt += line.length();
			}

			file.close();

			return cnt;
		}

		return -1;
	}

	string directory_name()
	{
		return this->dir;
	}

	string file_name()
	{
		return this->text_path;
	}
};