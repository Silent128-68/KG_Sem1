#pragma once

namespace Tishchenko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	//float lines2[] = {
	//	// Яблоко
	//	0.5f, 2.5f, 0.5f, 3.5f, // левая сторона яблока
	//	0.5f, 3.5f, 1.5f, 5.f, // вверх направо
	//	1.5f, 5.f, 2.f, 4.5f, // вправо вниз
	//	2.f, 4.5f, 2.f, 5.25f, // вверх
	//	2.f, 5.25f, 2.5f, 5.5f, // вверх вправо
	//	2.83f, 5.5f, 3.5f, 5.5f, // через 0.5 вправо
	//	3.5f, 5.5f, 3.f, 5.f, // вниз влево
	//	3.f, 5.f, 3.5f, 4.5f, // вниз вправо
	//	3.5f, 4.5f, 2.5f, 4.5f, // влево
	//	2.5f, 4.5f, 2.f, 5.f, // вверх влево
	//	3.f, 5.f, 2.f, 6.f, // палочка вверх влево
	//	2.f, 6.f, 2.5f, 6.5f, // палочка вверх вправо
	//	2.5f, 6.5f, 3.f, 5.f, // завершение палочки вниз вправо
	//	3.5f, 4.5f, 4.f, 4.f, // яблоко вниз вправо
	//	4.f, 4.f, 4.5f, 4.5f, // вверх вправо
	//	4.5f, 4.5f, 5.f, 3.5f, // вниз вправо
	//	5.f, 3.5f, 4.f, 3.f, // вниз влево
	//	4.f, 3.f, 3.5f, 4.f, // вверх влево
	//	3.5f, 4.f, 2.5f, 3.5f, // вниз влево
	//	2.5f, 3.5f, 2.f, 2.f, // вниз влево
	//	2.f, 2.f, 2.75f, 1.f, // вниз вправо
	//	2.75f, 1.f, 1.5f, 1.f, // влево
	//	1.5f, 1.f, 0.5f, 2.5f, // завершение яблока вверх влево
	//	// Ноги
	//	2.75f, 1.f, 3.f, 0.5f, // ботинок вниз вправо от нижней правой части яблока
	//	3.f, 0.5f, 5.f, 1.f, // ботинок вверх вправо
	//	5.f, 1.f, 4.f, 3.f, // ботинок вверх влево
	//	4.f, 3.f, 5.f, 3.5f, // штаны вверх влево от конца ботинка
	//	4.75f, 4.f, 7.8f, 4.f, // штаны вправо
	//	7.8f, 4.f, 7.5f, 2.5f, // штаны вниз влево
	//	7.5f, 2.5f, 7.f, 2.f, // штаны вниз влево
	//	7.f, 2.f, 7.f, 1.5f, // штаны вниз
	//	7.f, 1.5f, 5.f, 1.f, // завершение штанов вниз влево
	//	// Туловище
	//	7.8f, 4.f, 8.f, 4.5f, // спина вверх вправо
	//	8.f, 4.5f, 7.5f, 6.5f, // спина вверх влево
	//	7.5f, 6.5f, 6.5f, 7.5f, // спина вверх влево
	//	6.5f, 7.5f, 6.f, 7.f, // верх туловища вниз влево
	//	6.f, 7.f, 3.f, 5.5f, // верх туловища вниз влево
	//	2.5f, 5.5f, 1.5f, 5.5f, // рука слева от яблока влево от палочки
	//	1.5f, 5.5f, 1.5f, 5.f, // завершение руки слева от яблока вниз завершение
	//	6.5f, 4.5f, 4.5f, 4.5f, // начало руки справа от яблока с правой нижней части влево
	//	5.5f, 4.5f, 5.5f, 5.75f, // рукав правой руки ввверх
	//	6.5f, 6.f, 4.5f, 5.5f, // верх правой руки вниз влево
	//	4.5f, 5.5f, 5.f, 6.5f, // вверх вправо
	//	4.5f, 5.5f, 4.f, 6.f, // вверх влево правой руки
	//	4.f, 6.f, 3.5f, 5.5f, // вниз влево
	//	// Голова
	//	5.f, 6.5f, 3.5f, 7.f, // вверх влево
	//	3.5f, 7.f, 1.5f, 8.f, // вверх влево
	//	1.5f, 8.f, 1.f, 7.5f, // нос вниз влево
	//	1.f, 7.5f, 0.5f, 8.5f, // нос вверх влево
	//	0.5f, 8.5f, 1.5f, 8.5f, // нос влево
	//	1.5f, 8.5f, 1.5f, 8.f, // нос вниз
	//	1.5f, 8.5f, 3.f, 9.f, // голова от носа вверх вправо
	//	3.f, 9.f, 3.5f, 10.f, // голова вверх вправо
	//	3.5f, 10.f, 4.5f, 11.f, // голова вверх вправо
	//	3.5f, 10.f, 4.5f, 10.f, // верх глаза вправо
	//	4.5f, 10.f, 4.f, 8.5f, // глаз вниз влево
	//	4.f, 8.5f, 3.f, 9.f, // глаз вверх влево
	//	3.f, 9.f, 3.5f, 9.f, // глаз вправо
	//	3.5f, 9.f, 4.f, 10.f, // глаз вверх вправо
	//	4.5f, 11.f, 5.5f, 11.5f, // затылок вверх вправо
	//	5.5f, 11.5f, 5.f, 10.f, // затылок вниз влево
	//	5.f, 10.f, 6.f, 11.f, // затылок вверх вправо
	//	6.f, 11.f, 5.5f, 9.f, // затылок вниз влево
	//	5.5f, 9.f, 6.5f, 9.5f, // затылок вверх вправо
	//	6.5f, 9.5f, 6.f, 8.f, // затылок вниз влево
	//	6.f, 8.f, 7.f, 8.5f, // затылок вверх вправо
	//	7.f, 8.5f, 6.5f, 7.5f, // затылок вниз влево
	//	3.5f, 7.f, 5.f, 8.f, // улыбка вверх вправо
	//	5.f, 8.f, 5.f, 8.5f, // улыбка вверх
	//	// Иголки
	//	4.5f, 11.f, 3.5f, 10.5f, // по часовой
	//	3.5f, 10.5f, 4.f, 11.5f,
	//	4.f, 11.5f, 2.5f, 11.f,
	//	2.5f, 11.f, 4.f, 12.5f,
	//	4.f, 12.5f, 3.f, 13.5f,
	//	3.f, 13.5f, 4.5f, 13.f,
	//	4.5f, 13.f, 5.f, 14.f,
	//	5.f, 14.f, 5.5f, 13.f,
	//	5.5f, 13.f, 7.f, 14.f,
	//	7.f, 14.f, 7.f, 13.f,
	//	7.f, 13.f, 8.5f, 13.5f,
	//	8.5f, 13.5f, 8.f, 12.5f,
	//	8.f, 12.5f, 9.5f, 12.f,
	//	9.5f, 12.f, 8.5f, 11.5f,
	//	8.5f, 11.5f, 10.f, 10.5f,
	//	10.f, 10.5f, 10.25f, 10.f,
	//	10.25f, 10.f, 9.5f, 10.f,
	//	9.5f, 10.f, 10.f, 8.5f,
	//	10.f, 8.5f, 9.f, 8.5f,
	//	9.f, 8.5f, 10.f, 8.f,
	//	10.f, 8.f, 9.f, 7.5f,
	//	9.f, 7.5f, 10.f, 7.f,
	//	10.f, 7.f, 9.f, 6.5f,
	//	9.f, 6.5f, 10.f, 5.5f,
	//	10.f, 5.5f, 8.5f, 5.f,
	//	8.5f, 5.f, 10.f, 4.5f,
	//	10.f, 4.5f, 9.f, 4.f,
	//	9.f, 4.f, 10.f, 3.f,
	//	10.f, 3.f, 9.f, 2.5f,
	//	9.f, 2.5f, 10.f, 2.f,
	//	10.f, 2.f, 9.f, 1.4f,
	//	7.5f, 2.5f, 9.5f, 1.f,
	//	9.5f, 1.f, 7.f, 1.5f, // завершение иголок снизу справа
	//};

	float Vx;  // размер рисунка по горизонтали
	float Vy;  // размер рисунка по вертикали
	float aspectFig; // соотношение сторон рисунка

	mat3 T; // матрица, в которой накапливаются все преобразования
	mat3 initT;			// матрица начального преобразования

	vector<path> figure;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ btnOpen;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(265, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(102, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 321);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio; // значение - сохранять ли соотношение сторон рисунка?
	private: bool showHedgehog;

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		Pen^ blackPen = gcnew Pen(Color::Black, 2);

		for (int i = 0; i < figure.size(); i++) {
			path lines = figure[i]; // lines - очередная ломаная линия
			Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
			pen->Width = lines.thickness;

			vec2 start = normalize(T * vec3(lines.vertices[0], 1.0)); // первая начальная точка
			for (int j = 1; j < lines.vertices.size(); j++) { // цикл по конечным точкам (от единицы)
				vec2 end = normalize(T * vec3(lines.vertices[j], 1.0)); // конечная точка
				g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка отрезка
				start = end; // конечная точка текущего отрезка становится начальной точкой следующего
			}
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f; // координаты центра
		float Wcy = ClientRectangle.Height / 2.f; // текущего окна
		switch (e->KeyCode) {
		case Keys::Escape:
			T = initT;
			break;

		case Keys::Q:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в (Wcx, Wcy)
			T = rotate(0.01f) * T; // поворот на 0.01 радиан против часовой относительно
			// нового центра
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно
			break;
		case Keys::E:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в (Wcx, Wcy)
			T = rotate(-0.01f) * T; // поворот на 0.01 радиан по часовой относительно
			// нового центра
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно
			break;

		case Keys::W:
			T = translate(0.f, -1.f) * T; // сдвиг вверх на один пиксел
			break;
		case Keys::S:
			T = translate(0.f, 1.f) * T; // сдвиг вниз на один пиксел
			break;
		case Keys::A:
			T = translate(-1.f, 0.f) * T; // сдвиг влево на один пиксел
			break;
		case Keys::D:
			T = translate(1.f, 0.f) * T; // сдвиг вправо на один пиксел
			break;

		case Keys::R:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в (Wcx, Wcy)
			T = rotate(0.05f) * T; // поворот на 0.05 радиан против часовой относительно
			// нового центра
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно
			break;
		case Keys::Y:
			T = translate(-Wcx, -Wcy) * T; // перенос начала координат в (Wcx, Wcy)
			T = rotate(-0.05f) * T; // поворот на 0.01 радиан по часовой относительно
			// нового центра
			T = translate(Wcx, Wcy) * T; // перенос начала координат обратно
			break;

		case Keys::T:
			T = translate(0.f, -10.f) * T; // сдвиг вверх на один пиксел
			break;
		case Keys::G:
			T = translate(0.f, 10.f) * T; // сдвиг вниз на один пиксел
			break;
		case Keys::F:
			T = translate(-10.f, 0.f) * T; // сдвиг влево на один пиксел
			break;
		case Keys::H:
			T = translate(10.f, 0.f) * T; // сдвиг вправо на один пиксел
			break;
		default:
			break;
		}
		Refresh();
	}

	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// в файловом диалоге нажата кновка OK
			// перезапись имени файла из openFileDialog->FileName в fileName
			wchar_t fileName[1024]; // переменная, в которой посимвольно сохраним имя файла
			for (int i = 0; i < openFileDialog->FileName->Length; i++)
				fileName[i] = openFileDialog->FileName[i];
			fileName[openFileDialog->FileName->Length] = '\0';
			
			// объявление и открытие файла
			ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				// файл успешно открыт
				figure.clear(); // очищаем имеющийся список ломаных
				// временные переменные для чтения из файла
				float thickness = 2; // толщина со значением по умолчанию 2
				float r, g, b; // составляющие цвета
				r = g = b = 0; // значение составляющих цвета по умолчанию (черный)
				string cmd; // строка для считывания имени команды
				// непосредственно работа с файлом
				string str; // строка, в которую считываем строки файла
				getline(in, str); // считываем из входного файла первую строку
				while (in) { // если очередная строка считана успешно
					// обрабатываем строку
					if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
						// прочитанная строка не пуста и не комментарий
						stringstream s(str); // строковый поток из строки str
						s >> cmd;
						if (cmd == "frame") { // размеры изображения
							s >> Vx >> Vy; // считываем глобальные значение Vx и Vy
							aspectFig = Vx / Vy;
							float Wx = ClientRectangle.Width; // размер окна по горизонтали
							float Wy = ClientRectangle.Height; // размер окна по вертикали

							float aspectForm = Wx / Wy; // соотношение сторон окна рисования
							// коэффициенты увеличения при сохранении исходного соотношения сторон
							float S = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
							float Ty = S * Vy; // смещение в положительную сторону по оси Oy после смены знака
							initT = translate(0.f, Ty) * scale(S, -S); // преобразования применяются справа налево
							// сначала масштабирование, а потом перенос
							// в initT совмещаем эти два преобразования
							T = initT;
						}
						else if (cmd == "color") { // цвет линии
							s >> r >> g >> b; // считываем три составляющие цвета
						}
						else if (cmd == "thickness") { // толщина линии
							s >> thickness; // считываем значение толщины
						}
						else if (cmd == "path") { // набор точек
							vector<vec2> vertices; // список точек ломаной
							int N; // количество точек
							s >> N;
							string str1; // дополнительная строка для чтения из файла
							while (N > 0) { // пока не все точки считали
								getline(in, str1); // считываем в str1 из входного файла очередную строку
								// так как файл корректный, то на конец файла проверять не нужно
								if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
									// прочитанная строка не пуста и не комментарий
									// значит в ней пара координат
									float x, y; // переменные для считывания
									stringstream s1(str1); // еще один строковый поток из строки str1
									s1 >> x >> y;
									vertices.push_back(vec2(x, y)); // добавляем точку в список
									N--; // уменьшаем счетчик после успешного считывания точки
								}
							}
							// все точки считаны, генерируем ломаную (path) и кладем ее в список figure
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
						}
					}
					// считываем очередную строку
					getline(in, str);
				}
				Refresh();
			}
		}
	}
};
}
