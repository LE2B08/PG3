#include <vector>
#include <memory>

#include "Dog.h"
#include "Cat.h"
#include "HumanBaby.h"

int main()
{
	///// ========================================================
	/////						autoを使う場合
	///// ========================================================

	//// Animalポインタのベクターにインスタンスを格納
	//std::vector<std::unique_ptr<Animal>> animals;
	//animals.push_back(std::make_unique<Dog>());
	//animals.push_back(std::make_unique<Cat>());
	//animals.push_back(std::make_unique<HumanBaby>());

	//// 各動物の鳴き声を表示（ポリモーフィズムの実例）
	//for (const auto& animal : animals)
	//{
	//	animal->MakeSound();
	//}


	/// ========================================================
	///					autoを使わない場合
	/// ========================================================

	// Animalポインタのベクターにインスタンスを格納
	std::vector<std::unique_ptr<Animal>> animals;

	// 明示的に unique_ptr<Animal> 型を指定
	std::unique_ptr<Animal> dog = std::make_unique<Dog>();
	std::unique_ptr<Animal> cat = std::make_unique<Cat>();
	std::unique_ptr<Animal> humanbaby = std::make_unique<HumanBaby>();

	animals.push_back(std::move(dog));
	animals.push_back(std::move(cat));
	animals.push_back(std::move(humanbaby));

	// 各動物の鳴き声を表示（ポリモーフィズムの実例）
	for (const std::unique_ptr<Animal>& animal : animals) {
		animal->MakeSound();
	}

	return 0;
}
