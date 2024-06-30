#pragma once
#include "Core.h"
#include "Layer.h"

#include <vector>
namespace Hazel {

	class HAZEL_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;//m_LayerInsert一直指向容器的开始
		//不用iterator，因为容器发生变化后，iterator就失效了
	};
}