/**
 * @copyright
 * ====================================================================
 * Copyright (c) 2000-2004 CollabNet.  All rights reserved.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.  The terms
 * are also available at http://subversion.tigris.org/license-1.html.
 * If newer versions of this license are posted there, you may use a
 * newer version instead, at your option.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://subversion.tigris.org/.
 * ====================================================================
 * @endcopyright
 *
 * @file svn_dav.h
 * @brief Code related to WebDAV/DeltaV usage in Subversion.
 */




#ifndef SVN_DAV_H
#define SVN_DAV_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/** This is the MIME type that Subversion uses for its "svndiff" format.
 *
 * This is an application type, for the "svn" vendor. The specific subtype
 * is "svndiff".
 */
#define SVN_SVNDIFF_MIME_TYPE "application/vnd.svn-svndiff"


/** This header is *TEMPORARILY* used to transmit the delta base to the
 * server. It contains a version resource URL for what is on the client.
 */
#define SVN_DAV_DELTA_BASE_HEADER "X-SVN-VR-Base"

/** This header is used when an svn client wants to trigger specific
 * svn server behaviors.  Normal WebDAV or DeltaV clients won't use it.
 */
#define SVN_DAV_OPTIONS_HEADER "X-SVN-Options"

/** Specific options that can appear in the options-header: */
#define SVN_DAV_OPTION_NO_MERGE_RESPONSE "no-merge-response"
#define SVN_DAV_OPTION_LOCK_BREAK        "lock-break"
#define SVN_DAV_OPTION_LOCK_STEAL        "lock-steal"
#define SVN_DAV_OPTION_RELEASE_LOCKS     "release-locks"
#define SVN_DAV_OPTION_KEEP_LOCKS        "keep-locks"

/** This header is used when an svn client wants to tell mod_dav_svn
 * exactly what revision of a resource it thinks it's operating on.
 * (For example, an svn server can use it to validate a DELETE request.)
 * Normal WebDAV or DeltaV clients won't use it.
 */
#define SVN_DAV_VERSION_NAME_HEADER "X-SVN-Version-Name"

/** A header generated by mod_dav_svn whenever it responds
    successfully to a LOCK request.  Only svn clients will notice it,
    and use it to fill in svn_lock_t->creation_date.   */
#define SVN_DAV_CREATIONDATE_HEADER "X-SVN-Creation-Date"

/** These headers are for client and server to verify that the base
 * and the result of a change transmission are the same on both
 * sides, regardless of what transformations (svndiff deltification,
 * gzipping, etc) the data may have gone through in between.  
 *
 * The result md5 is always used whenever file contents are
 * transferred, because every transmission has a resulting text.
 *
 * The base md5 is used to verify the base text against which svndiff
 * data is being applied.  Note that even for svndiff transmissions,
 * base verification is not strictly necessary (and may therefore be
 * unimplemented), as any error will be caught by the verification of
 * the final result.  However, if the problem is that the base text is
 * corrupt, the error will be caught earlier if the base md5 is used.
 *
 * Normal WebDAV or DeltaV clients don't use these.
 */
#define SVN_DAV_BASE_FULLTEXT_MD5_HEADER "X-SVN-Base-Fulltext-MD5"
#define SVN_DAV_RESULT_FULLTEXT_MD5_HEADER "X-SVN-Result-Fulltext-MD5"

/* ### should add strings for the various XML elements in the reports
   ### and things. also the custom prop names. etc.
*/

/** The svn-specific object that is placed within a <D:error> response.
 *
 * @defgroup svn_dav_error svn_dav errors
 * @{ */

/** The error object's namespace */
#define SVN_DAV_ERROR_NAMESPACE "svn:"

/** The error object's tag */
#define SVN_DAV_ERROR_TAG       "error"

/** @} */


/** General property (xml) namespaces that will be used by both ra_dav
 * and mod_dav_svn for marshalling properties.
 *
 * @defgroup svn_dav_property_xml_namespaces dav property namespaces
 * @{
 */

/** A property stored in the fs and wc, begins with 'svn:', and is
 * interpreted either by client or server.
 */
#define SVN_DAV_PROP_NS_SVN "http://subversion.tigris.org/xmlns/svn/"

/** A property stored in the fs and wc, but totally ignored by svn
 * client and server.
 *
 * A property simply invented by the users.
 */
#define SVN_DAV_PROP_NS_CUSTOM "http://subversion.tigris.org/xmlns/custom/"

/** A property purely generated and consumed by the network layer, not
 * seen by either fs or wc.
 */
#define SVN_DAV_PROP_NS_DAV "http://subversion.tigris.org/xmlns/dav/"

/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* SVN_DAV_H */
