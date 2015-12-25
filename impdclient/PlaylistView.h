/*******************************************************************************
 * iPhone Project : iMPDclient                                                 *
 * Copyright (C) 2008 Boris Nagels <joogels@gmail.com>                         *
 *******************************************************************************
 * $LastChangedDate:: 2008-01-29 22:02:23 +0100 (Tue, 29 Jan 2008)           $ *
 * $LastChangedBy:: boris                                                    $ *
 * $LastChangedRevision:: 140                                                $ *
 * $Id:: application.h 140 2008-01-29 21:02:23Z boris                        $ *
 *******************************************************************************
 *  This program is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by       *
 *  the Free Software Foundation, either version 3 of the License, or          *
 *  (at your option) any later version.                                        *
 *                                                                             *
 *  This program is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 *  GNU General Public License for more details.                               *
 *                                                                             *
 *  You should have received a copy of the GNU General Public License          *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.      *
 *******************************************************************************/

#import <Foundation/Foundation.h>
#import <Foundation/NSDictionary.h>
#import <UIKit/UIKit.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UITextLabel.h>
#import <UIKit/UITableCell.h>
#import <GraphicsServices/GraphicsServices.h>		// For GSEvent.

#import "libmpd/libmpd.h"

//////////////////////////////////////////////////////////////////////////
// Forward declarations.
//////////////////////////////////////////////////////////////////////////

@class MPDClientApplication;

//////////////////////////////////////////////////////////////////////////
// PlaylistTableCell: class definition.
//////////////////////////////////////////////////////////////////////////

@interface PlaylistTableCell : UITableCell
{
	UITextLabel* _songName;
	UITextLabel* _artistName;
	UIImageView* _playImage;
	
@public
	int _songID;
}
- (void)dealloc;
- (id)initWithSong:(NSString *)song artist:(NSString *)artistInfo current:(BOOL)currentSong;
@end

//////////////////////////////////////////////////////////////////////////
// PlaylistTable: class definition.
//////////////////////////////////////////////////////////////////////////

@interface PlaylistTable : UITable
{
	struct timeval _last;
	int _lastClickX;
	int _lastClickY;
}
- (void)initialize;
- (void)mouseUp:(GSEvent *)event;
@end

//////////////////////////////////////////////////////////////////////////
// PlaylistView: class definition.
//////////////////////////////////////////////////////////////////////////

@interface PlaylistView : UIView
{
	UINavigationBar* _navBar;
	UINavigationItem* _title;
	BOOL m_Editing;

	MpdObj* _mpdServer;
	MPDClientApplication* _app;
	
	NSMutableArray* _songs;
	PlaylistTable* _table;
}
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)frame;
- (void)initialize:(MPDClientApplication *)app mpd:(MpdObj *)mpdServer;

- (void)showPlaylist;
- (void)updateTitle;
- (void)doubleTap:(id)sender;
@end
