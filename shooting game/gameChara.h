#pragma once
class gameChara
{
private:
	
public:
	Vec2 pos_;
	Vec2 moveDir_;
	double speed_;
	Texture tex_;
	RectF myRect_;
	bool isAlive_;
	gameChara();
	gameChara(Vec2 _pos);
	~gameChara();
	void SetCharaRect(SizeF _size);
	void SetAlive(bool _alive) { isAlive_ = _alive; }
	void SetSpeed(double _speed) { speed_ = _speed; }
	void moveDir(Vec2 _movedir) { moveDir_ = _movedir; }
	void SetPosition(Vec2 _pos);
	RectF GetCharaRect() { return myRect_; }
	bool isActive() { return isAlive_; }
	void DeActivate() { isAlive_=false; }
	void Activate() { isAlive_ = true; }
	bool IsMyRectHit(RectF _rect);
	virtual void UpDate();
	virtual void Draw();
};
