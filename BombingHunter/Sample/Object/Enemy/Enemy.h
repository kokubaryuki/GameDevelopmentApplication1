#pragma once
#pragma once

#include"../GameObject.h"

class  Enemy : public GameObject
{
private:
	int animation[2];     //�A�j���[�V�����摜
	int animation_count;  //�A�j���[�V��������
	int flip_flag;        //���]�t���O

protected:
	Vector2D location;
	Vector2D box_size;
	
public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;  //����������
	virtual void Update() override;      //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;    //�I��������


private:
	
	//�A�j���[�V��������
	void AnimeControl();


public:

	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const; 
	//�����蔻��̑傫�����擾
};


