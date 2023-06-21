#ifndef OD_GR_UI_COMPONENT_H
#define OD_GR_UI_COMPONENT_H

/**************************************************************************************
* OpenDraft:    GUI Component Base Class                                              *
*-------------------------------------------------------------------------------------*
* Filename:     OdComponent.h                                                         *
* Contributors: James Hodgkins                                                        *
* Date:         June 21, 2023                                                         *
* Copyright:    �2023 OpenDraft. All Rights Reserved.                                 *
*-------------------------------------------------------------------------------------*
* Description:                                                                        *
*   Base class for GUI components.                                                    *
***************************************************************************************/



#include <string>
#include <vector>
#include "System/OdCore.h"
#include "Graphics/UI/OdInput.h"
#include <nanovg.h>

using namespace OD::System;

namespace OD
{
	namespace Graphics
	{
		class OdComponent
		{
		protected:
			// Mouse state
			bool mouseOver = false;
			bool mouseEnter = false;
			bool mouseLeave = false;
			bool mouseDown = false;

			// Parent-child relationship
			OdComponent* parent;                        // Parent container control for the control.
			std::vector<OdComponent*> childComponents;   // Child Components

		public:
			// Basic properties
			std::string name;                           // Name of the control.
			OdPoint location = { 0,0 };                 // Location of component
			OdPoint size = { 50,50 };                    // Size of component

			// Appearance properties
			float strokeWidth;                           // Width of stroke
			void* font;                                  // Font of the text displayed by the control.
			OdColour backColour;                         // Background colour of the control.
			OdColour stroke;                             // Stroke colour
			OdColour foreColour;                         // Foreground colour of the control.

			// Behavior properties
			bool enabled = true;                         // Control is enabled or disabled.
			bool show;                                   // Visible or hidden.
			bool overflow;                               // Determines whether the control can draw child components outside its boundaries.

			int tabIndex;                                // Tab order of the control within its container.
			// Text properties
			std::string text;                            // Text associated with the control.

			// Resource properties
			OdResourceManager* resourceManager;          // Pointer to injected resource manager.

			// Virtual Functions
			virtual void const onFrame(NVGcontext* aContext) = 0;

			// Setters
			void setLocation(int aX, int aY);
			void setText(std::string s);

			// Getters
			std::string getText();
			OdPoint getLocation() const;
			OdPoint getRelativeLocation() const;
			OdPoint getSize() const;

			// Mouse Events
			bool isMouseOver() const;
			bool isMouseEnter() const;
			bool isMouseLeave() const;
			bool isMouseDown() const;

			// Child Component Management
			void addChildControl(OdComponent* aChild);

			// Event Handling
			void processEvents(GrInputMap* aInput);

			// Drawing
			void drawChildComponents(NVGcontext* aContext);
			void setNoOverflow(NVGcontext* aContext);
			void allowOverflow(NVGcontext* aContext);
		};

	} // namespace Graphics
} // namespace OD

#endif // OD_GR_UI_COMPONENT_H
