.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419B0_C32E90
/* C32E90 802419B0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C32E94 802419B4 AFB20038 */  sw        $s2, 0x38($sp)
/* C32E98 802419B8 0080902D */  daddu     $s2, $a0, $zero
/* C32E9C 802419BC AFBF0048 */  sw        $ra, 0x48($sp)
/* C32EA0 802419C0 AFB50044 */  sw        $s5, 0x44($sp)
/* C32EA4 802419C4 AFB40040 */  sw        $s4, 0x40($sp)
/* C32EA8 802419C8 AFB3003C */  sw        $s3, 0x3c($sp)
/* C32EAC 802419CC AFB10034 */  sw        $s1, 0x34($sp)
/* C32EB0 802419D0 AFB00030 */  sw        $s0, 0x30($sp)
/* C32EB4 802419D4 8E510148 */  lw        $s1, 0x148($s2)
/* C32EB8 802419D8 86240008 */  lh        $a0, 8($s1)
/* C32EBC 802419DC 0C00EABB */  jal       get_npc_unsafe
/* C32EC0 802419E0 00A0802D */   daddu    $s0, $a1, $zero
/* C32EC4 802419E4 8E43000C */  lw        $v1, 0xc($s2)
/* C32EC8 802419E8 0240202D */  daddu     $a0, $s2, $zero
/* C32ECC 802419EC 8C650000 */  lw        $a1, ($v1)
/* C32ED0 802419F0 0C0B1EAF */  jal       get_variable
/* C32ED4 802419F4 0040A82D */   daddu    $s5, $v0, $zero
/* C32ED8 802419F8 AFA00010 */  sw        $zero, 0x10($sp)
/* C32EDC 802419FC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32EE0 80241A00 8C630094 */  lw        $v1, 0x94($v1)
/* C32EE4 80241A04 AFA30014 */  sw        $v1, 0x14($sp)
/* C32EE8 80241A08 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32EEC 80241A0C 8C630080 */  lw        $v1, 0x80($v1)
/* C32EF0 80241A10 AFA30018 */  sw        $v1, 0x18($sp)
/* C32EF4 80241A14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32EF8 80241A18 8C630088 */  lw        $v1, 0x88($v1)
/* C32EFC 80241A1C AFA3001C */  sw        $v1, 0x1c($sp)
/* C32F00 80241A20 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32F04 80241A24 8C63008C */  lw        $v1, 0x8c($v1)
/* C32F08 80241A28 27B40010 */  addiu     $s4, $sp, 0x10
/* C32F0C 80241A2C AFA30020 */  sw        $v1, 0x20($sp)
/* C32F10 80241A30 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C32F14 80241A34 3C014282 */  lui       $at, 0x4282
/* C32F18 80241A38 44810000 */  mtc1      $at, $f0
/* C32F1C 80241A3C 8C630090 */  lw        $v1, 0x90($v1)
/* C32F20 80241A40 0040982D */  daddu     $s3, $v0, $zero
/* C32F24 80241A44 E7A00028 */  swc1      $f0, 0x28($sp)
/* C32F28 80241A48 A7A0002C */  sh        $zero, 0x2c($sp)
/* C32F2C 80241A4C 16000005 */  bnez      $s0, .L80241A64
/* C32F30 80241A50 AFA30024 */   sw       $v1, 0x24($sp)
/* C32F34 80241A54 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C32F38 80241A58 30420004 */  andi      $v0, $v0, 4
/* C32F3C 80241A5C 10400020 */  beqz      $v0, .L80241AE0
/* C32F40 80241A60 00000000 */   nop      
.L80241A64:
/* C32F44 80241A64 2404F7FF */  addiu     $a0, $zero, -0x801
/* C32F48 80241A68 AE400070 */  sw        $zero, 0x70($s2)
/* C32F4C 80241A6C A6A0008E */  sh        $zero, 0x8e($s5)
/* C32F50 80241A70 8E2200CC */  lw        $v0, 0xcc($s1)
/* C32F54 80241A74 8EA30000 */  lw        $v1, ($s5)
/* C32F58 80241A78 8C420000 */  lw        $v0, ($v0)
/* C32F5C 80241A7C 00641824 */  and       $v1, $v1, $a0
/* C32F60 80241A80 AEA30000 */  sw        $v1, ($s5)
/* C32F64 80241A84 AEA20028 */  sw        $v0, 0x28($s5)
/* C32F68 80241A88 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C32F6C 80241A8C 8C420098 */  lw        $v0, 0x98($v0)
/* C32F70 80241A90 54400005 */  bnel      $v0, $zero, .L80241AA8
/* C32F74 80241A94 2402FDFF */   addiu    $v0, $zero, -0x201
/* C32F78 80241A98 34620200 */  ori       $v0, $v1, 0x200
/* C32F7C 80241A9C 2403FFF7 */  addiu     $v1, $zero, -9
/* C32F80 80241AA0 080906AC */  j         .L80241AB0
/* C32F84 80241AA4 00431024 */   and      $v0, $v0, $v1
.L80241AA8:
/* C32F88 80241AA8 00621024 */  and       $v0, $v1, $v0
/* C32F8C 80241AAC 34420008 */  ori       $v0, $v0, 8
.L80241AB0:
/* C32F90 80241AB0 AEA20000 */  sw        $v0, ($s5)
/* C32F94 80241AB4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C32F98 80241AB8 30420004 */  andi      $v0, $v0, 4
/* C32F9C 80241ABC 10400007 */  beqz      $v0, .L80241ADC
/* C32FA0 80241AC0 24020063 */   addiu    $v0, $zero, 0x63
/* C32FA4 80241AC4 AE420070 */  sw        $v0, 0x70($s2)
/* C32FA8 80241AC8 AE400074 */  sw        $zero, 0x74($s2)
/* C32FAC 80241ACC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C32FB0 80241AD0 2403FFFB */  addiu     $v1, $zero, -5
/* C32FB4 80241AD4 00431024 */  and       $v0, $v0, $v1
/* C32FB8 80241AD8 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241ADC:
/* C32FBC 80241ADC AE20006C */  sw        $zero, 0x6c($s1)
.L80241AE0:
/* C32FC0 80241AE0 8E420070 */  lw        $v0, 0x70($s2)
/* C32FC4 80241AE4 2842001E */  slti      $v0, $v0, 0x1e
/* C32FC8 80241AE8 10400009 */  beqz      $v0, .L80241B10
/* C32FCC 80241AEC 00000000 */   nop      
/* C32FD0 80241AF0 8E22006C */  lw        $v0, 0x6c($s1)
/* C32FD4 80241AF4 14400006 */  bnez      $v0, .L80241B10
/* C32FD8 80241AF8 00000000 */   nop      
/* C32FDC 80241AFC 0C090116 */  jal       func_80240458_C31938
/* C32FE0 80241B00 0240202D */   daddu    $a0, $s2, $zero
/* C32FE4 80241B04 10400002 */  beqz      $v0, .L80241B10
/* C32FE8 80241B08 2402001E */   addiu    $v0, $zero, 0x1e
/* C32FEC 80241B0C AE420070 */  sw        $v0, 0x70($s2)
.L80241B10:
/* C32FF0 80241B10 8E430070 */  lw        $v1, 0x70($s2)
/* C32FF4 80241B14 2C620064 */  sltiu     $v0, $v1, 0x64
/* C32FF8 80241B18 1040004E */  beqz      $v0, .L80241C54
/* C32FFC 80241B1C 00031080 */   sll      $v0, $v1, 2
/* C33000 80241B20 3C018024 */  lui       $at, %hi(D_80244D28)
/* C33004 80241B24 00220821 */  addu      $at, $at, $v0
/* C33008 80241B28 8C224D28 */  lw        $v0, %lo(D_80244D28)($at)
/* C3300C 80241B2C 00400008 */  jr        $v0
/* C33010 80241B30 00000000 */   nop      
/* C33014 80241B34 0240202D */  daddu     $a0, $s2, $zero
/* C33018 80241B38 0260282D */  daddu     $a1, $s3, $zero
/* C3301C 80241B3C 0C0902C8 */  jal       func_80240B20_C32000
/* C33020 80241B40 0280302D */   daddu    $a2, $s4, $zero
/* C33024 80241B44 0240202D */  daddu     $a0, $s2, $zero
/* C33028 80241B48 0260282D */  daddu     $a1, $s3, $zero
/* C3302C 80241B4C 0C09031E */  jal       func_80240C78_C32158
/* C33030 80241B50 0280302D */   daddu    $a2, $s4, $zero
/* C33034 80241B54 08090715 */  j         .L80241C54
/* C33038 80241B58 00000000 */   nop      
/* C3303C 80241B5C 0240202D */  daddu     $a0, $s2, $zero
/* C33040 80241B60 0260282D */  daddu     $a1, $s3, $zero
/* C33044 80241B64 0C0903C8 */  jal       dgb_03_UnkNpcAIFunc1
/* C33048 80241B68 0280302D */   daddu    $a2, $s4, $zero
/* C3304C 80241B6C 0240202D */  daddu     $a0, $s2, $zero
/* C33050 80241B70 0260282D */  daddu     $a1, $s3, $zero
/* C33054 80241B74 0C0903F8 */  jal       func_80240FE0_C324C0
/* C33058 80241B78 0280302D */   daddu    $a2, $s4, $zero
/* C3305C 80241B7C 08090715 */  j         .L80241C54
/* C33060 80241B80 00000000 */   nop      
/* C33064 80241B84 0240202D */  daddu     $a0, $s2, $zero
/* C33068 80241B88 0260282D */  daddu     $a1, $s3, $zero
/* C3306C 80241B8C 0C090467 */  jal       func_8024119C_C3267C
/* C33070 80241B90 0280302D */   daddu    $a2, $s4, $zero
/* C33074 80241B94 08090715 */  j         .L80241C54
/* C33078 80241B98 00000000 */   nop      
/* C3307C 80241B9C 0240202D */  daddu     $a0, $s2, $zero
/* C33080 80241BA0 0260282D */  daddu     $a1, $s3, $zero
/* C33084 80241BA4 0C090494 */  jal       dgb_03_NpcJumpFunc2
/* C33088 80241BA8 0280302D */   daddu    $a2, $s4, $zero
/* C3308C 80241BAC 0240202D */  daddu     $a0, $s2, $zero
/* C33090 80241BB0 0260282D */  daddu     $a1, $s3, $zero
/* C33094 80241BB4 0C0904B1 */  jal       dgb_03_NpcJumpFunc
/* C33098 80241BB8 0280302D */   daddu    $a2, $s4, $zero
/* C3309C 80241BBC 08090715 */  j         .L80241C54
/* C330A0 80241BC0 00000000 */   nop      
/* C330A4 80241BC4 0240202D */  daddu     $a0, $s2, $zero
/* C330A8 80241BC8 0260282D */  daddu     $a1, $s3, $zero
/* C330AC 80241BCC 0C0904CF */  jal       func_8024133C_C3281C
/* C330B0 80241BD0 0280302D */   daddu    $a2, $s4, $zero
/* C330B4 80241BD4 0240202D */  daddu     $a0, $s2, $zero
/* C330B8 80241BD8 0260282D */  daddu     $a1, $s3, $zero
/* C330BC 80241BDC 0C09051B */  jal       func_8024146C_C3294C
/* C330C0 80241BE0 0280302D */   daddu    $a2, $s4, $zero
/* C330C4 80241BE4 08090715 */  j         .L80241C54
/* C330C8 80241BE8 00000000 */   nop      
/* C330CC 80241BEC 0240202D */  daddu     $a0, $s2, $zero
/* C330D0 80241BF0 0260282D */  daddu     $a1, $s3, $zero
/* C330D4 80241BF4 0C090563 */  jal       dgb_03_UnkNpcDurationFlagFunc
/* C330D8 80241BF8 0280302D */   daddu    $a2, $s4, $zero
/* C330DC 80241BFC 08090715 */  j         .L80241C54
/* C330E0 80241C00 00000000 */   nop      
/* C330E4 80241C04 0C090094 */  jal       dgb_03_UnkNpcAIFunc6
/* C330E8 80241C08 0240202D */   daddu    $a0, $s2, $zero
/* C330EC 80241C0C 0C0900AF */  jal       dgb_03_UnkNpcAIFunc7
/* C330F0 80241C10 0240202D */   daddu    $a0, $s2, $zero
/* C330F4 80241C14 8E430070 */  lw        $v1, 0x70($s2)
/* C330F8 80241C18 24020020 */  addiu     $v0, $zero, 0x20
/* C330FC 80241C1C 1462000D */  bne       $v1, $v0, .L80241C54
/* C33100 80241C20 00000000 */   nop      
/* C33104 80241C24 0C0900CB */  jal       dgb_03_UnkNpcAIFunc8
/* C33108 80241C28 0240202D */   daddu    $a0, $s2, $zero
/* C3310C 80241C2C 8E430070 */  lw        $v1, 0x70($s2)
/* C33110 80241C30 24020021 */  addiu     $v0, $zero, 0x21
/* C33114 80241C34 14620007 */  bne       $v1, $v0, .L80241C54
/* C33118 80241C38 00000000 */   nop      
/* C3311C 80241C3C 0C090101 */  jal       dgb_03_UnkNpcAIFunc5
/* C33120 80241C40 0240202D */   daddu    $a0, $s2, $zero
/* C33124 80241C44 08090715 */  j         .L80241C54
/* C33128 80241C48 00000000 */   nop      
/* C3312C 80241C4C 0C0129CF */  jal       func_8004A73C
/* C33130 80241C50 0240202D */   daddu    $a0, $s2, $zero
.L80241C54:
/* C33134 80241C54 8FBF0048 */  lw        $ra, 0x48($sp)
/* C33138 80241C58 8FB50044 */  lw        $s5, 0x44($sp)
/* C3313C 80241C5C 8FB40040 */  lw        $s4, 0x40($sp)
/* C33140 80241C60 8FB3003C */  lw        $s3, 0x3c($sp)
/* C33144 80241C64 8FB20038 */  lw        $s2, 0x38($sp)
/* C33148 80241C68 8FB10034 */  lw        $s1, 0x34($sp)
/* C3314C 80241C6C 8FB00030 */  lw        $s0, 0x30($sp)
/* C33150 80241C70 0000102D */  daddu     $v0, $zero, $zero
/* C33154 80241C74 03E00008 */  jr        $ra
/* C33158 80241C78 27BD0050 */   addiu    $sp, $sp, 0x50
