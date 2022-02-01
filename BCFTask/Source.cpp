#include "TextFileOperation.cpp";

int main()
{
    TextFileOperation text("Test", "Test/f1.txt");

	int max_threads = omp_get_max_threads();

	cout << "Max threads = " << max_threads << endl;

	if (max_threads >= 4)max_threads = 4;

#pragma omp parallel num_threads(max_threads) shared(text)
	{
#pragma omp sections nowait
		{
#pragma omp section
			{
				cout << "Number of files in " << text.directory_name() << " directory: " << text.files_counter_in_directory() << endl;
			}

#pragma omp section
			{
				cout << "Number of lines in " << text.file_name() << " file: " << text.lines_counter_in_txt_file() << endl;
			}

#pragma omp section
			{
				cout << "Number of words in " << text.file_name() << " file: " << text.words_counter_in_txt_file() << endl;
			}

#pragma omp section
			{
				cout << "Number of letters in " << text.file_name() << " file: " << text.letters_counter_in_txt_file() << endl;
			}
		}
	}
    
    return 0;
}