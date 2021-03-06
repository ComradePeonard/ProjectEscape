#pragma once

#include "GameObject.h"
#include "Corner.h"

namespace esc
{

	GameObject::GameObject(sf::Vector2f p_v2fPosition, sf::Vector2f p_v2fSize, bool p_bInteractable, int p_iObjectId, sf::Sprite *p_xSprite)
	{
		m_xSprite = p_xSprite;

		m_bInteractable = p_bInteractable;

		setPosition(p_v2fPosition);

		m_v2fSize = p_v2fSize;

		m_iObjectId = p_iObjectId;
	}

	void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(*m_xSprite, states);
	}

	void GameObject::update(float deltaTime)
	{
		createCorners();
	}

	void GameObject::setSprite(sf::Sprite *p_xSprite)
	{
		m_xSprite = p_xSprite;
	}

	sf::Sprite *GameObject::getSprite()
	{
		return m_xSprite;
	}

	void GameObject::setSize(sf::Vector2f p_v2fSize)
	{
		m_v2fSize = p_v2fSize;
	}

	sf::Vector2f GameObject::getSize()
	{
		return m_v2fSize;
	}

	void GameObject::setInteractable(bool p_bInteractable)
	{
		m_bInteractable = p_bInteractable;
	}

	bool GameObject::getInteractable()
	{
		return m_bInteractable;
	}

	void GameObject::setTransparent(bool p_bIsTransparent)
	{
		m_bIsTransparent = p_bIsTransparent;
	}

	bool GameObject::getTransparent()
	{
		return m_bIsTransparent;
	}

	void GameObject::createCorners()
	{
		for (auto corner : m_vCorners)
		{
			delete corner;
			corner = nullptr;
		}

		m_vCorners.clear();

		m_vCorners.push_back(new Corner(getPosition(), sf::Color(255, 255, 255, 0), m_iObjectId));
		m_vCorners.push_back(new Corner(sf::Vector2f(getPosition().x + m_v2fSize.x, getPosition().y), sf::Color(255, 255, 255, 0), m_iObjectId));
		m_vCorners.push_back(new Corner(sf::Vector2f(getPosition().x, getPosition().y + m_v2fSize.y), sf::Color(255, 255, 255, 0), m_iObjectId));
		m_vCorners.push_back(new Corner(sf::Vector2f(getPosition().x + m_v2fSize.x, getPosition().y + m_v2fSize.y), sf::Color(255, 255, 255, 0), m_iObjectId));
	}

	std::vector<Corner*> GameObject::getCorners()
	{
		return m_vCorners;
	}

	void GameObject::setId(int p_iObjectId)
	{
		m_iObjectId = p_iObjectId;
	}

	int GameObject::getId()
	{
		return m_iObjectId;
	}

}