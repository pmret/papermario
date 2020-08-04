.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel initialize_status_menu
/* 080DE4 800E7934 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 080DE8 800E7938 AFB10014 */  sw    $s1, 0x14($sp)
/* 080DEC 800E793C 3C118011 */  lui   $s1, 0x8011
/* 080DF0 800E7940 2631EF58 */  addiu $s1, $s1, -0x10a8
/* 080DF4 800E7944 2402000C */  addiu $v0, $zero, 0xc
/* 080DF8 800E7948 AFBF001C */  sw    $ra, 0x1c($sp)
/* 080DFC 800E794C AFB20018 */  sw    $s2, 0x18($sp)
/* 080E00 800E7950 AFB00010 */  sw    $s0, 0x10($sp)
/* 080E04 800E7954 A6220034 */  sh    $v0, 0x34($s1)
/* 080E08 800E7958 2402FF9C */  addiu $v0, $zero, -0x64
/* 080E0C 800E795C 3C038011 */  lui   $v1, 0x8011
/* 080E10 800E7960 2463F290 */  addiu $v1, $v1, -0xd70
/* 080E14 800E7964 3C018011 */  lui   $at, 0x8011
/* 080E18 800E7968 A420CD10 */  sh    $zero, -0x32f0($at)
/* 080E1C 800E796C 3C018011 */  lui   $at, 0x8011
/* 080E20 800E7970 A420CD12 */  sh    $zero, -0x32ee($at)
/* 080E24 800E7974 A6220036 */  sh    $v0, 0x36($s1)
/* 080E28 800E7978 A220003A */  sb    $zero, 0x3a($s1)
/* 080E2C 800E797C 90640010 */  lbu   $a0, 0x10($v1)
/* 080E30 800E7980 240200D2 */  addiu $v0, $zero, 0xd2
/* 080E34 800E7984 A6220038 */  sh    $v0, 0x38($s1)
/* 080E38 800E7988 A220003B */  sb    $zero, 0x3b($s1)
/* 080E3C 800E798C A2200044 */  sb    $zero, 0x44($s1)
/* 080E40 800E7990 A2200045 */  sb    $zero, 0x45($s1)
/* 080E44 800E7994 A2200046 */  sb    $zero, 0x46($s1)
/* 080E48 800E7998 A220004A */  sb    $zero, 0x4a($s1)
/* 080E4C 800E799C A220004B */  sb    $zero, 0x4b($s1)
/* 080E50 800E79A0 A220004C */  sb    $zero, 0x4c($s1)
/* 080E54 800E79A4 A220004D */  sb    $zero, 0x4d($s1)
/* 080E58 800E79A8 A220004E */  sb    $zero, 0x4e($s1)
/* 080E5C 800E79AC A220004F */  sb    $zero, 0x4f($s1)
/* 080E60 800E79B0 A2200050 */  sb    $zero, 0x50($s1)
/* 080E64 800E79B4 A2200051 */  sb    $zero, 0x51($s1)
/* 080E68 800E79B8 A2200054 */  sb    $zero, 0x54($s1)
/* 080E6C 800E79BC A2200055 */  sb    $zero, 0x55($s1)
/* 080E70 800E79C0 A2200056 */  sb    $zero, 0x56($s1)
/* 080E74 800E79C4 A2200047 */  sb    $zero, 0x47($s1)
/* 080E78 800E79C8 A2200052 */  sb    $zero, 0x52($s1)
/* 080E7C 800E79CC 90620002 */  lbu   $v0, 2($v1)
/* 080E80 800E79D0 90650005 */  lbu   $a1, 5($v1)
/* 080E84 800E79D4 9466000C */  lhu   $a2, 0xc($v1)
/* 080E88 800E79D8 94630290 */  lhu   $v1, 0x290($v1)
/* 080E8C 800E79DC 00042600 */  sll   $a0, $a0, 0x18
/* 080E90 800E79E0 00042603 */  sra   $a0, $a0, 0x18
/* 080E94 800E79E4 A222003D */  sb    $v0, 0x3d($s1)
/* 080E98 800E79E8 2402FFFF */  addiu $v0, $zero, -1
/* 080E9C 800E79EC A225003E */  sb    $a1, 0x3e($s1)
/* 080EA0 800E79F0 A6260040 */  sh    $a2, 0x40($s1)
/* 080EA4 800E79F4 A6240042 */  sh    $a0, 0x42($s1)
/* 080EA8 800E79F8 A6230048 */  sh    $v1, 0x48($s1)
/* 080EAC 800E79FC A2200053 */  sb    $zero, 0x53($s1)
/* 080EB0 800E7A00 A222006E */  sb    $v0, 0x6e($s1)
/* 080EB4 800E7A04 2402FFFF */  addiu $v0, $zero, -1
/* 080EB8 800E7A08 A220003C */  sb    $zero, 0x3c($s1)
/* 080EBC 800E7A0C A2200057 */  sb    $zero, 0x57($s1)
/* 080EC0 800E7A10 A2200058 */  sb    $zero, 0x58($s1)
/* 080EC4 800E7A14 A2200059 */  sb    $zero, 0x59($s1)
/* 080EC8 800E7A18 A220005A */  sb    $zero, 0x5a($s1)
/* 080ECC 800E7A1C A220006C */  sb    $zero, 0x6c($s1)
/* 080ED0 800E7A20 A220006D */  sb    $zero, 0x6d($s1)
/* 080ED4 800E7A24 0C03A5EE */  jal   func_800E97B8
/* 080ED8 800E7A28 AE220064 */   sw    $v0, 0x64($s1)
/* 080EDC 800E7A2C 3C048011 */  lui   $a0, 0x8011
/* 080EE0 800E7A30 24848248 */  addiu $a0, $a0, -0x7db8
/* 080EE4 800E7A34 0C050529 */  jal   create_icon
/* 080EE8 800E7A38 00000000 */   nop   
/* 080EEC 800E7A3C 0040802D */  daddu $s0, $v0, $zero
/* 080EF0 800E7A40 0200202D */  daddu $a0, $s0, $zero
/* 080EF4 800E7A44 24050080 */  addiu $a1, $zero, 0x80
/* 080EF8 800E7A48 0C051280 */  jal   set_icon_flags
/* 080EFC 800E7A4C AE300000 */   sw    $s0, ($s1)
/* 080F00 800E7A50 0200202D */  daddu $a0, $s0, $zero
/* 080F04 800E7A54 0C05128B */  jal   clear_icon_flags
/* 080F08 800E7A58 34058000 */   ori   $a1, $zero, 0x8000
/* 080F0C 800E7A5C 3C048011 */  lui   $a0, 0x8011
/* 080F10 800E7A60 24848518 */  addiu $a0, $a0, -0x7ae8
/* 080F14 800E7A64 0C050529 */  jal   create_icon
/* 080F18 800E7A68 00000000 */   nop   
/* 080F1C 800E7A6C 0040802D */  daddu $s0, $v0, $zero
/* 080F20 800E7A70 0200202D */  daddu $a0, $s0, $zero
/* 080F24 800E7A74 24050080 */  addiu $a1, $zero, 0x80
/* 080F28 800E7A78 0C051280 */  jal   set_icon_flags
/* 080F2C 800E7A7C AE300004 */   sw    $s0, 4($s1)
/* 080F30 800E7A80 0200202D */  daddu $a0, $s0, $zero
/* 080F34 800E7A84 0C05128B */  jal   clear_icon_flags
/* 080F38 800E7A88 34058000 */   ori   $a1, $zero, 0x8000
/* 080F3C 800E7A8C 3C048011 */  lui   $a0, 0x8011
/* 080F40 800E7A90 24848270 */  addiu $a0, $a0, -0x7d90
/* 080F44 800E7A94 0C050529 */  jal   create_icon
/* 080F48 800E7A98 00000000 */   nop   
/* 080F4C 800E7A9C 0040802D */  daddu $s0, $v0, $zero
/* 080F50 800E7AA0 0200202D */  daddu $a0, $s0, $zero
/* 080F54 800E7AA4 24050080 */  addiu $a1, $zero, 0x80
/* 080F58 800E7AA8 0C051280 */  jal   set_icon_flags
/* 080F5C 800E7AAC AE300008 */   sw    $s0, 8($s1)
/* 080F60 800E7AB0 0200202D */  daddu $a0, $s0, $zero
/* 080F64 800E7AB4 0C05128B */  jal   clear_icon_flags
/* 080F68 800E7AB8 34058000 */   ori   $a1, $zero, 0x8000
/* 080F6C 800E7ABC 3C048011 */  lui   $a0, 0x8011
/* 080F70 800E7AC0 24848538 */  addiu $a0, $a0, -0x7ac8
/* 080F74 800E7AC4 0C050529 */  jal   create_icon
/* 080F78 800E7AC8 00000000 */   nop   
/* 080F7C 800E7ACC 0040802D */  daddu $s0, $v0, $zero
/* 080F80 800E7AD0 0200202D */  daddu $a0, $s0, $zero
/* 080F84 800E7AD4 24050080 */  addiu $a1, $zero, 0x80
/* 080F88 800E7AD8 0C051280 */  jal   set_icon_flags
/* 080F8C 800E7ADC AE30000C */   sw    $s0, 0xc($s1)
/* 080F90 800E7AE0 0200202D */  daddu $a0, $s0, $zero
/* 080F94 800E7AE4 0C05128B */  jal   clear_icon_flags
/* 080F98 800E7AE8 34058000 */   ori   $a1, $zero, 0x8000
/* 080F9C 800E7AEC 3C048011 */  lui   $a0, 0x8011
/* 080FA0 800E7AF0 24848558 */  addiu $a0, $a0, -0x7aa8
/* 080FA4 800E7AF4 0C050529 */  jal   create_icon
/* 080FA8 800E7AF8 00000000 */   nop   
/* 080FAC 800E7AFC 0040802D */  daddu $s0, $v0, $zero
/* 080FB0 800E7B00 0200202D */  daddu $a0, $s0, $zero
/* 080FB4 800E7B04 24050080 */  addiu $a1, $zero, 0x80
/* 080FB8 800E7B08 0C051280 */  jal   set_icon_flags
/* 080FBC 800E7B0C AE300010 */   sw    $s0, 0x10($s1)
/* 080FC0 800E7B10 0200202D */  daddu $a0, $s0, $zero
/* 080FC4 800E7B14 0C05128B */  jal   clear_icon_flags
/* 080FC8 800E7B18 34058000 */   ori   $a1, $zero, 0x8000
/* 080FCC 800E7B1C 3C048008 */  lui   $a0, 0x8008
/* 080FD0 800E7B20 24840FC4 */  addiu $a0, $a0, 0xfc4
/* 080FD4 800E7B24 0C050529 */  jal   create_icon
/* 080FD8 800E7B28 00000000 */   nop   
/* 080FDC 800E7B2C 0040802D */  daddu $s0, $v0, $zero
/* 080FE0 800E7B30 0200202D */  daddu $a0, $s0, $zero
/* 080FE4 800E7B34 24050080 */  addiu $a1, $zero, 0x80
/* 080FE8 800E7B38 0C051280 */  jal   set_icon_flags
/* 080FEC 800E7B3C AE300014 */   sw    $s0, 0x14($s1)
/* 080FF0 800E7B40 0200202D */  daddu $a0, $s0, $zero
/* 080FF4 800E7B44 0C05128B */  jal   clear_icon_flags
/* 080FF8 800E7B48 34058000 */   ori   $a1, $zero, 0x8000
/* 080FFC 800E7B4C 3C048011 */  lui   $a0, 0x8011
/* 081000 800E7B50 248486AC */  addiu $a0, $a0, -0x7954
/* 081004 800E7B54 0C050529 */  jal   create_icon
/* 081008 800E7B58 00000000 */   nop   
/* 08100C 800E7B5C 0040802D */  daddu $s0, $v0, $zero
/* 081010 800E7B60 0200202D */  daddu $a0, $s0, $zero
/* 081014 800E7B64 24050080 */  addiu $a1, $zero, 0x80
/* 081018 800E7B68 0C051280 */  jal   set_icon_flags
/* 08101C 800E7B6C AE300018 */   sw    $s0, 0x18($s1)
/* 081020 800E7B70 0200202D */  daddu $a0, $s0, $zero
/* 081024 800E7B74 0C05128B */  jal   clear_icon_flags
/* 081028 800E7B78 34058000 */   ori   $a1, $zero, 0x8000
/* 08102C 800E7B7C 3C048010 */  lui   $a0, 0x8010
/* 081030 800E7B80 24844BEC */  addiu $a0, $a0, 0x4bec
/* 081034 800E7B84 0C050529 */  jal   create_icon
/* 081038 800E7B88 00000000 */   nop   
/* 08103C 800E7B8C 0040802D */  daddu $s0, $v0, $zero
/* 081040 800E7B90 0200202D */  daddu $a0, $s0, $zero
/* 081044 800E7B94 24050080 */  addiu $a1, $zero, 0x80
/* 081048 800E7B98 0C051280 */  jal   set_icon_flags
/* 08104C 800E7B9C AE30001C */   sw    $s0, 0x1c($s1)
/* 081050 800E7BA0 0200202D */  daddu $a0, $s0, $zero
/* 081054 800E7BA4 0C05128B */  jal   clear_icon_flags
/* 081058 800E7BA8 34058000 */   ori   $a1, $zero, 0x8000
/* 08105C 800E7BAC 3C128011 */  lui   $s2, 0x8011
/* 081060 800E7BB0 26528068 */  addiu $s2, $s2, -0x7f98
/* 081064 800E7BB4 0C050529 */  jal   create_icon
/* 081068 800E7BB8 0240202D */   daddu $a0, $s2, $zero
/* 08106C 800E7BBC 0040802D */  daddu $s0, $v0, $zero
/* 081070 800E7BC0 0200202D */  daddu $a0, $s0, $zero
/* 081074 800E7BC4 24050082 */  addiu $a1, $zero, 0x82
/* 081078 800E7BC8 0C051280 */  jal   set_icon_flags
/* 08107C 800E7BCC AE300020 */   sw    $s0, 0x20($s1)
/* 081080 800E7BD0 0200202D */  daddu $a0, $s0, $zero
/* 081084 800E7BD4 0C05128B */  jal   clear_icon_flags
/* 081088 800E7BD8 34058000 */   ori   $a1, $zero, 0x8000
/* 08108C 800E7BDC 0C050529 */  jal   create_icon
/* 081090 800E7BE0 0240202D */   daddu $a0, $s2, $zero
/* 081094 800E7BE4 0040802D */  daddu $s0, $v0, $zero
/* 081098 800E7BE8 0200202D */  daddu $a0, $s0, $zero
/* 08109C 800E7BEC 24050082 */  addiu $a1, $zero, 0x82
/* 0810A0 800E7BF0 0C051280 */  jal   set_icon_flags
/* 0810A4 800E7BF4 AE300024 */   sw    $s0, 0x24($s1)
/* 0810A8 800E7BF8 0200202D */  daddu $a0, $s0, $zero
/* 0810AC 800E7BFC 0C05128B */  jal   clear_icon_flags
/* 0810B0 800E7C00 34058000 */   ori   $a1, $zero, 0x8000
/* 0810B4 800E7C04 0C050529 */  jal   create_icon
/* 0810B8 800E7C08 0240202D */   daddu $a0, $s2, $zero
/* 0810BC 800E7C0C 0040802D */  daddu $s0, $v0, $zero
/* 0810C0 800E7C10 0200202D */  daddu $a0, $s0, $zero
/* 0810C4 800E7C14 24050082 */  addiu $a1, $zero, 0x82
/* 0810C8 800E7C18 0C051280 */  jal   set_icon_flags
/* 0810CC 800E7C1C AE300028 */   sw    $s0, 0x28($s1)
/* 0810D0 800E7C20 0200202D */  daddu $a0, $s0, $zero
/* 0810D4 800E7C24 0C05128B */  jal   clear_icon_flags
/* 0810D8 800E7C28 34058000 */   ori   $a1, $zero, 0x8000
/* 0810DC 800E7C2C 0C050529 */  jal   create_icon
/* 0810E0 800E7C30 0240202D */   daddu $a0, $s2, $zero
/* 0810E4 800E7C34 0040802D */  daddu $s0, $v0, $zero
/* 0810E8 800E7C38 0200202D */  daddu $a0, $s0, $zero
/* 0810EC 800E7C3C 24050082 */  addiu $a1, $zero, 0x82
/* 0810F0 800E7C40 0C051280 */  jal   set_icon_flags
/* 0810F4 800E7C44 AE30002C */   sw    $s0, 0x2c($s1)
/* 0810F8 800E7C48 0200202D */  daddu $a0, $s0, $zero
/* 0810FC 800E7C4C 0C05128B */  jal   clear_icon_flags
/* 081100 800E7C50 34058000 */   ori   $a1, $zero, 0x8000
/* 081104 800E7C54 3C048011 */  lui   $a0, 0x8011
/* 081108 800E7C58 248483D8 */  addiu $a0, $a0, -0x7c28
/* 08110C 800E7C5C 0C050529 */  jal   create_icon
/* 081110 800E7C60 00000000 */   nop   
/* 081114 800E7C64 0040802D */  daddu $s0, $v0, $zero
/* 081118 800E7C68 0200202D */  daddu $a0, $s0, $zero
/* 08111C 800E7C6C 24050080 */  addiu $a1, $zero, 0x80
/* 081120 800E7C70 0C051280 */  jal   set_icon_flags
/* 081124 800E7C74 AE300030 */   sw    $s0, 0x30($s1)
/* 081128 800E7C78 0200202D */  daddu $a0, $s0, $zero
/* 08112C 800E7C7C 0C05128B */  jal   clear_icon_flags
/* 081130 800E7C80 34058000 */   ori   $a1, $zero, 0x8000
/* 081134 800E7C84 0C03C357 */  jal   func_800F0D5C
/* 081138 800E7C88 00000000 */   nop   
/* 08113C 800E7C8C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 081140 800E7C90 8FB20018 */  lw    $s2, 0x18($sp)
/* 081144 800E7C94 8FB10014 */  lw    $s1, 0x14($sp)
/* 081148 800E7C98 8FB00010 */  lw    $s0, 0x10($sp)
/* 08114C 800E7C9C 03E00008 */  jr    $ra
/* 081150 800E7CA0 27BD0020 */   addiu $sp, $sp, 0x20

