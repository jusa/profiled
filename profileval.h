
/*
* This file is part of profile-qt
*
* Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
*
* Contact: Sakari Poussa <sakari.poussa@nokia.com>
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
* in the documentation  and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation nor the names of its contributors may be used to endorse or promote products derived 
* from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
* BUT NOT LIMITED TO, THE * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
* IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, * INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR * * BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 * @brief Profile value structure.
 *
 * @file profileval.h
 *
 * Profile value structure.
 *
 * <p>
 * Copyright (C) 2008 Nokia. All rights reserved.
 *
 * @author Simo Piiroinen <simo.piiroinen@nokia.com>
 */


#ifndef PROFILEVALUE_H_
# define PROFILEVALUE_H_

# ifdef __cplusplus
extern "C" {
# elif 0
} /* fool JED indentation ... */
# endif

/* ------------------------------------------------------------------------- *
 * profileval_t
 * ------------------------------------------------------------------------- */

/** \brief shorthand
 */
typedef struct profileval_t profileval_t;

/** \brief key value type -triplet
 *
 * Profile data entries have: name, value and type.
 *
 * The profileval_t structure is used to convey this
 * information from profile daemon to client applications.
 */

struct profileval_t
{
  /** \brief Key string
   */
  char *pv_key;

  /** \brief Value string
   */
  char *pv_val;

  /** \brief Type string
   */
  char *pv_type;
};

/**
 * Profile value constructor.
 *
 * @param self value structure
 */
void profileval_ctor(profileval_t *self);

/**
 * Profile value destructor.
 *
 * @param self value structure
 */
void profileval_dtor(profileval_t *self);

/**
 * Extended profile value constructor.
 *
 * @param self value structure
 * @param key  key string
 * @param val  value string
 * @param type type string
 *
 */
void profileval_ctor_ex(profileval_t *self, const char *key, const char *val, const char *type);

/**
 * Utility function for freeing an array of profile values.
 *
 * The vec must either be NULL or
 * contain valid profile value entries
 * and a terminator entry with NULL pv_key entry.
 *
 * @param vec array of profile values
 */
void profileval_free_vector(profileval_t *vec);

# ifdef __cplusplus
};
# endif

#endif /* PROFILEVALUE_H_ */