#include <util/flatbuffers.h>
#include <flatbuffers/monster_generated.h>

namespace basic_namespace
{
void test_flatbuffers()
{
	// 建立一个串行缓冲区算法

	flatbuffers::FlatBufferBuilder builder;

	// 序列化以把剑

	auto weapon_one_name = builder.CreateString("Sword");

	short weapon_one_damage = 3;

	// 序列化以吧斧头

	auto weapon_two_name = builder.CreateString("Axe");

	short weapon_two_damage = 5;

	// 创建武器

	auto sword = MyGame::Sample::CreateWeapon(builder, weapon_one_name, weapon_one_damage);

	auto axe = MyGame::Sample::CreateWeapon(builder, weapon_two_name, weapon_two_damage);

	// 使用std:vector 创建一个flatbuffer的向量类型

	std::vector<flatbuffers::Offset<MyGame::Sample::Weapon>> weapns_vector;

	weapns_vector.push_back(sword);

	weapns_vector.push_back(axe);

	auto weapons = builder.CreateVector(weapns_vector);

	//

	auto position = MyGame::Sample::Vec3(1.0f, 2.0f, 3.0f);

	auto name = builder.CreateString("CCMonster");

	unsigned char inv_data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto inventory = builder.CreateVector(inv_data, 10);

	auto orc = CreateMonster(builder, &position, 150, 80, name, inventory, MyGame::Sample::Color_Red, weapons, MyGame::Sample::Equipment_Weapon, axe.Union());

	builder.Finish(orc);

	const void* buf = builder.GetBufferPointer();
	size_t siz = builder.GetSize();
	auto monster = MyGame::Sample::GetMonster(buf);

	// Get and test some scalar types from the FlatBuffer.

	assert(monster->hp() == 80);

	assert(monster->mana() == 150); // default

	assert(monster->name()->str() == "CCMonster");

	// Get and test a field of the FlatBuffer's `struct`.

	auto pos = monster->pos();

	assert(pos);

	assert(pos->z() == 3.0f);

	(void)pos;

	// Get a test an element from the `inventory` FlatBuffer's `vector`.

	auto inv = monster->inventory();

	assert(inv);

	assert(inv->Get(9) == 9);

	(void)inv;

	// Get and test the `weapons` FlatBuffers's `vector`.

	std::string expected_weapon_names[] = {"Sword", "Axe"};

	short expected_weapon_damages[] = {3, 5};

	auto weps = monster->weapons();

	for (unsigned int i = 0; i < weps->size(); i++)
	{
		assert(weps->Get(i)->name()->str() == expected_weapon_names[i]);

		assert(weps->Get(i)->damage() == expected_weapon_damages[i]);
	}

	(void)expected_weapon_names;

	(void)expected_weapon_damages;

	// Get and test the `Equipment` union (`equipped` field).

	assert(monster->equipped_type() == MyGame::Sample::Equipment_Weapon);

	auto equipped = static_cast<const MyGame::Sample::Weapon*>(monster->equipped());

	assert(equipped->name()->str() == "Axe");

	assert(equipped->damage() == 5);

	(void)equipped;

	printf("The FlatBuffer was successfully created and verified!\n");
}
} // namespace basic_namespace