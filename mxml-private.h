/*
 * Private definitions for microxml, a micro XML-like file parsing library.
 *
 * Copyright 2003-2010 by Michael R Sweet.
 * Copyright 2011-2012 by Luka Perkov.
 *
 * These coded instructions, statements, and computer programs are the
 * property of Michael R Sweet and Luka Perkov. They are protected by
 * Federal copyright law. Distribution and use rights are outlined in
 * the file "COPYING" which should have been included with this file.
 * If this file is missing or damaged, see the license at:
 *
 *     http://www.minixml.org/
 */

/*
 * Include necessary headers...
 */

#include "config.h"
#include "microxml.h"


/*
 * Global, per-thread data...
 */

typedef struct _mxml_global_s
{
  void	(*error_cb)(const char *);
  int	num_entity_cbs;
  int	(*entity_cbs[100])(const char *name);
  int	wrap;
  mxml_custom_load_cb_t	custom_load_cb;
  mxml_custom_save_cb_t	custom_save_cb;
} _mxml_global_t;


/*
 * Functions...
 */

extern _mxml_global_t	*_mxml_global(void);
extern int		_mxml_entity_cb(const char *name);

