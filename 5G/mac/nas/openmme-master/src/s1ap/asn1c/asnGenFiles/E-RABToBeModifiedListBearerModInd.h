/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU-Contents"
 * 	found in "./asn1c/S1AP-PDU-Contents.asn"
 * 	`asn1c -fcompound-names -fno-include-deps -gen-PER -findirect-choice -pdu=S1AP-PDU`
 */

#ifndef	_E_RABToBeModifiedListBearerModInd_H_
#define	_E_RABToBeModifiedListBearerModInd_H_


#include <asn_application.h>

/* Including external dependencies */
#include "E-RAB-IE-ContainerList.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E-RABToBeModifiedListBearerModInd */
typedef E_RAB_IE_ContainerList_456P6_t	 E_RABToBeModifiedListBearerModInd_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_E_RABToBeModifiedListBearerModInd_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_E_RABToBeModifiedListBearerModInd;
asn_struct_free_f E_RABToBeModifiedListBearerModInd_free;
asn_struct_print_f E_RABToBeModifiedListBearerModInd_print;
asn_constr_check_f E_RABToBeModifiedListBearerModInd_constraint;
ber_type_decoder_f E_RABToBeModifiedListBearerModInd_decode_ber;
der_type_encoder_f E_RABToBeModifiedListBearerModInd_encode_der;
xer_type_decoder_f E_RABToBeModifiedListBearerModInd_decode_xer;
xer_type_encoder_f E_RABToBeModifiedListBearerModInd_encode_xer;
oer_type_decoder_f E_RABToBeModifiedListBearerModInd_decode_oer;
oer_type_encoder_f E_RABToBeModifiedListBearerModInd_encode_oer;
per_type_decoder_f E_RABToBeModifiedListBearerModInd_decode_uper;
per_type_encoder_f E_RABToBeModifiedListBearerModInd_encode_uper;
per_type_decoder_f E_RABToBeModifiedListBearerModInd_decode_aper;
per_type_encoder_f E_RABToBeModifiedListBearerModInd_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _E_RABToBeModifiedListBearerModInd_H_ */
#include <asn_internal.h>
