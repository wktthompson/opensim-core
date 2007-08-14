#ifndef _IntegCallbackSet_h_
#define _IntegCallbackSet_h_
// IntegCallbackSet.h
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
* Copyright (c) 2005, Stanford University. All rights reserved. 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions
* are met: 
*  - Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer. 
*  - Redistributions in binary form must reproduce the above copyright 
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the distribution. 
*  - Neither the name of the Stanford University nor the names of its 
*    contributors may be used to endorse or promote products derived 
*    from this software without specific prior written permission. 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
* POSSIBILITY OF SUCH DAMAGE. 
*/

/* Note: This code was originally developed by Realistic Dynamics Inc. 
 * Author: Frank C. Anderson 
 */


// INCLUDES
#include "CallbackSet.h"
#include "IntegCallback.h"


//=============================================================================
//=============================================================================
/**
 * A class for holding and managing a set of integration callbacks for
 * a model.
 *
 * @author Frank C. Anderson
 * @version 1.0
 */
namespace OpenSim { 

class Model;

class OSIMSIMULATION_API IntegCallbackSet : public Set<Callback>
{

//=============================================================================
// DATA
//=============================================================================
protected:
	/** Model on which the callbacks have been set. */
	Model *_model;

//=============================================================================
// METHODS
//=============================================================================
	//--------------------------------------------------------------------------
	// CONSTRUCTION
	//--------------------------------------------------------------------------
public:
	IntegCallbackSet(Model *aModel=0);
	virtual ~IntegCallbackSet();
private:
	void setNull();
public:

	//--------------------------------------------------------------------------
	// GET AND SET
	//--------------------------------------------------------------------------
	void setModel(Model *aModel);
	Model* getModel();
	void setOn(bool aTrueFalse);
	void setOn(const Array<bool> &aOn);
	Array<bool> getOn() const;
	IntegCallback* getIntegCallback(int aIndex) const;

	//--------------------------------------------------------------------------
	// CALLBACKS
	//--------------------------------------------------------------------------
	virtual void
		begin(int aStep,double aDT,double aT,
		double *aX,double *aY,double *aYP=NULL,double *aDYDT=NULL,void *aClientData=NULL);
	virtual void
		step(double *aXPrev,double *aYPrev,double *aYPPrev,int aStep,double aDT,double aT,
		double *aX,double *aY,double *aYP=NULL,double *aDYDT=NULL,void *aClientData=NULL);
	virtual void
		end(int aStep,double aDT,double aT,
		double *aX,double *aY,double *aYP=NULL,double *aDYDT=NULL,void *aClientData=NULL);

//=============================================================================
};	// END of class IntegCallbackSet

}; //namespace
//=============================================================================
//=============================================================================

#endif // __IntegCallbackSet_h__


