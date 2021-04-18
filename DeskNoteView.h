/*
 * Original copyright 2000 by Colin Stewart (http://www.owlfish.com/).
 * All rights reserved.
 * Distributed under the terms of the BSD (3-clause) License.
 *
 * Authors:
 *		Janus2, 2015
 *
 */


#ifndef _DESKNOTEVIEW_H
#define _DESKNOTEVIEW_H

#include <Application.h>
#include <InterfaceKit.h>
#include <String.h>

#include "DeskNoteApp.h"
#include "DeskNoteTextView.h"
#include "FontColourWindow.h"


// Launch DeskNotes.
#define DN_LAUNCH 'dnLN'
// Request to open the Font and Colour window.
#define DN_FNT_CLR 'dnFC'
// Request to change the current font and colour.
#define DN_CHG_FNT_CLR 'dnCF'

#define DN_NOTE_SAVE 'dnSV'


class DeskNoteTextView;

class DeskNoteView : public BView {
public:
	DeskNoteView(BRect rect);
	DeskNoteView(BMessage* data);
	~DeskNoteView();

	virtual void 		DetachedFromWindow();
	virtual status_t 	Archive(BMessage* data, bool deep = true) const;
	virtual void 		Draw(BRect rect);
	virtual void 		MessageReceived(BMessage* msg);
	virtual void 		FrameResized(float width, float height);
	virtual void 		MouseDown(BPoint point);
	virtual void 		CascadeFontAndColour(void);
	virtual void 		SaveNote(BMessage* msg);
	virtual void 		RestoreNote(BMessage* msg);

	static BArchivable* Instantiate(BMessage* data);
	static int32 		ResizeViewMethod(void* data);

	static const char 	defaultText[];
	static const char 	aboutText[];

private:
	void 				_ShowContextMenu(BPoint where);
	bool 				WeAreAReplicant;
	DeskNoteTextView*	textView;
	BRect 				ourSize;
	FontColourWindow* 	propertiesWindow;
	BMessage* 			orginalSettings;
	BPopUpMenu* 		popupMenu;
	rgb_color 			background;
	rgb_color 			foreground;
	rgb_color 			widgetcolour;
	BDragger* 			dragger;
};

#endif // _DESKNOTEVIEW_H
