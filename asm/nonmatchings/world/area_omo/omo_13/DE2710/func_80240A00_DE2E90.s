.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A00_DE2E90
/* DE2E90 80240A00 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DE2E94 80240A04 AFB30054 */  sw        $s3, 0x54($sp)
/* DE2E98 80240A08 0080982D */  daddu     $s3, $a0, $zero
/* DE2E9C 80240A0C AFBF0060 */  sw        $ra, 0x60($sp)
/* DE2EA0 80240A10 AFB5005C */  sw        $s5, 0x5c($sp)
/* DE2EA4 80240A14 AFB40058 */  sw        $s4, 0x58($sp)
/* DE2EA8 80240A18 AFB20050 */  sw        $s2, 0x50($sp)
/* DE2EAC 80240A1C AFB1004C */  sw        $s1, 0x4c($sp)
/* DE2EB0 80240A20 AFB00048 */  sw        $s0, 0x48($sp)
/* DE2EB4 80240A24 8E710148 */  lw        $s1, 0x148($s3)
/* DE2EB8 80240A28 86240008 */  lh        $a0, 8($s1)
/* DE2EBC 80240A2C 0C00EABB */  jal       get_npc_unsafe
/* DE2EC0 80240A30 00A0802D */   daddu    $s0, $a1, $zero
/* DE2EC4 80240A34 8E63000C */  lw        $v1, 0xc($s3)
/* DE2EC8 80240A38 0260202D */  daddu     $a0, $s3, $zero
/* DE2ECC 80240A3C 8C650000 */  lw        $a1, ($v1)
/* DE2ED0 80240A40 0C0B1EAF */  jal       get_variable
/* DE2ED4 80240A44 0040902D */   daddu    $s2, $v0, $zero
/* DE2ED8 80240A48 AFA00018 */  sw        $zero, 0x18($sp)
/* DE2EDC 80240A4C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE2EE0 80240A50 8C630030 */  lw        $v1, 0x30($v1)
/* DE2EE4 80240A54 AFA3001C */  sw        $v1, 0x1c($sp)
/* DE2EE8 80240A58 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE2EEC 80240A5C 8C63001C */  lw        $v1, 0x1c($v1)
/* DE2EF0 80240A60 AFA30020 */  sw        $v1, 0x20($sp)
/* DE2EF4 80240A64 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE2EF8 80240A68 8C630024 */  lw        $v1, 0x24($v1)
/* DE2EFC 80240A6C AFA30024 */  sw        $v1, 0x24($sp)
/* DE2F00 80240A70 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE2F04 80240A74 8C630028 */  lw        $v1, 0x28($v1)
/* DE2F08 80240A78 27B50018 */  addiu     $s5, $sp, 0x18
/* DE2F0C 80240A7C AFA30028 */  sw        $v1, 0x28($sp)
/* DE2F10 80240A80 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DE2F14 80240A84 3C014282 */  lui       $at, 0x4282
/* DE2F18 80240A88 44810000 */  mtc1      $at, $f0
/* DE2F1C 80240A8C 8C63002C */  lw        $v1, 0x2c($v1)
/* DE2F20 80240A90 0040A02D */  daddu     $s4, $v0, $zero
/* DE2F24 80240A94 E7A00030 */  swc1      $f0, 0x30($sp)
/* DE2F28 80240A98 A7A00034 */  sh        $zero, 0x34($sp)
/* DE2F2C 80240A9C 16000005 */  bnez      $s0, .L80240AB4
/* DE2F30 80240AA0 AFA3002C */   sw       $v1, 0x2c($sp)
/* DE2F34 80240AA4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DE2F38 80240AA8 30420004 */  andi      $v0, $v0, 4
/* DE2F3C 80240AAC 10400044 */  beqz      $v0, .L80240BC0
/* DE2F40 80240AB0 00000000 */   nop      
.L80240AB4:
/* DE2F44 80240AB4 2404F7FF */  addiu     $a0, $zero, -0x801
/* DE2F48 80240AB8 AE600070 */  sw        $zero, 0x70($s3)
/* DE2F4C 80240ABC A640008E */  sh        $zero, 0x8e($s2)
/* DE2F50 80240AC0 8E2200CC */  lw        $v0, 0xcc($s1)
/* DE2F54 80240AC4 8E430000 */  lw        $v1, ($s2)
/* DE2F58 80240AC8 8C420000 */  lw        $v0, ($v0)
/* DE2F5C 80240ACC 00641824 */  and       $v1, $v1, $a0
/* DE2F60 80240AD0 AE430000 */  sw        $v1, ($s2)
/* DE2F64 80240AD4 AE420028 */  sw        $v0, 0x28($s2)
/* DE2F68 80240AD8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DE2F6C 80240ADC 8C420034 */  lw        $v0, 0x34($v0)
/* DE2F70 80240AE0 54400005 */  bnel      $v0, $zero, .L80240AF8
/* DE2F74 80240AE4 2402FDFF */   addiu    $v0, $zero, -0x201
/* DE2F78 80240AE8 34620200 */  ori       $v0, $v1, 0x200
/* DE2F7C 80240AEC 2403FFF7 */  addiu     $v1, $zero, -9
/* DE2F80 80240AF0 080902C0 */  j         .L80240B00
/* DE2F84 80240AF4 00431024 */   and      $v0, $v0, $v1
.L80240AF8:
/* DE2F88 80240AF8 00621024 */  and       $v0, $v1, $v0
/* DE2F8C 80240AFC 34420008 */  ori       $v0, $v0, 8
.L80240B00:
/* DE2F90 80240B00 AE420000 */  sw        $v0, ($s2)
/* DE2F94 80240B04 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DE2F98 80240B08 30420004 */  andi      $v0, $v0, 4
/* DE2F9C 80240B0C 10400004 */  beqz      $v0, .L80240B20
/* DE2FA0 80240B10 24020063 */   addiu    $v0, $zero, 0x63
/* DE2FA4 80240B14 AE620070 */  sw        $v0, 0x70($s3)
/* DE2FA8 80240B18 080902CE */  j         .L80240B38
/* DE2FAC 80240B1C AE600074 */   sw       $zero, 0x74($s3)
.L80240B20:
/* DE2FB0 80240B20 8E220000 */  lw        $v0, ($s1)
/* DE2FB4 80240B24 3C034000 */  lui       $v1, 0x4000
/* DE2FB8 80240B28 00431024 */  and       $v0, $v0, $v1
/* DE2FBC 80240B2C 10400002 */  beqz      $v0, .L80240B38
/* DE2FC0 80240B30 2402000C */   addiu    $v0, $zero, 0xc
/* DE2FC4 80240B34 AE620070 */  sw        $v0, 0x70($s3)
.L80240B38:
/* DE2FC8 80240B38 3C06BFFF */  lui       $a2, 0xbfff
/* DE2FCC 80240B3C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* DE2FD0 80240B40 27A50038 */  addiu     $a1, $sp, 0x38
/* DE2FD4 80240B44 2404FFFB */  addiu     $a0, $zero, -5
/* DE2FD8 80240B48 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DE2FDC 80240B4C 8E230000 */  lw        $v1, ($s1)
/* DE2FE0 80240B50 3C0142C8 */  lui       $at, 0x42c8
/* DE2FE4 80240B54 44810000 */  mtc1      $at, $f0
/* DE2FE8 80240B58 00441024 */  and       $v0, $v0, $a0
/* DE2FEC 80240B5C 00661824 */  and       $v1, $v1, $a2
/* DE2FF0 80240B60 AE2200B0 */  sw        $v0, 0xb0($s1)
/* DE2FF4 80240B64 AE230000 */  sw        $v1, ($s1)
/* DE2FF8 80240B68 864200A8 */  lh        $v0, 0xa8($s2)
/* DE2FFC 80240B6C 27A70040 */  addiu     $a3, $sp, 0x40
/* DE3000 80240B70 E7A00044 */  swc1      $f0, 0x44($sp)
/* DE3004 80240B74 C6460038 */  lwc1      $f6, 0x38($s2)
/* DE3008 80240B78 C640003C */  lwc1      $f0, 0x3c($s2)
/* DE300C 80240B7C C6420040 */  lwc1      $f2, 0x40($s2)
/* DE3010 80240B80 44822000 */  mtc1      $v0, $f4
/* DE3014 80240B84 00000000 */  nop       
/* DE3018 80240B88 46802120 */  cvt.s.w   $f4, $f4
/* DE301C 80240B8C 27A20044 */  addiu     $v0, $sp, 0x44
/* DE3020 80240B90 46040000 */  add.s     $f0, $f0, $f4
/* DE3024 80240B94 E7A60038 */  swc1      $f6, 0x38($sp)
/* DE3028 80240B98 E7A20040 */  swc1      $f2, 0x40($sp)
/* DE302C 80240B9C E7A0003C */  swc1      $f0, 0x3c($sp)
/* DE3030 80240BA0 AFA20010 */  sw        $v0, 0x10($sp)
/* DE3034 80240BA4 8E440080 */  lw        $a0, 0x80($s2)
/* DE3038 80240BA8 0C0372DF */  jal       func_800DCB7C
/* DE303C 80240BAC 27A6003C */   addiu    $a2, $sp, 0x3c
/* DE3040 80240BB0 10400003 */  beqz      $v0, .L80240BC0
/* DE3044 80240BB4 00000000 */   nop      
/* DE3048 80240BB8 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DE304C 80240BBC E640003C */  swc1      $f0, 0x3c($s2)
.L80240BC0:
/* DE3050 80240BC0 8E630070 */  lw        $v1, 0x70($s3)
/* DE3054 80240BC4 2C620064 */  sltiu     $v0, $v1, 0x64
/* DE3058 80240BC8 10400038 */  beqz      $v0, .L80240CAC
/* DE305C 80240BCC 00031080 */   sll      $v0, $v1, 2
/* DE3060 80240BD0 3C018024 */  lui       $at, 0x8024
/* DE3064 80240BD4 00220821 */  addu      $at, $at, $v0
/* DE3068 80240BD8 8C223090 */  lw        $v0, 0x3090($at)
/* DE306C 80240BDC 00400008 */  jr        $v0
/* DE3070 80240BE0 00000000 */   nop      
/* DE3074 80240BE4 0260202D */  daddu     $a0, $s3, $zero
/* DE3078 80240BE8 0280282D */  daddu     $a1, $s4, $zero
/* DE307C 80240BEC 0C012568 */  jal       func_800495A0
/* DE3080 80240BF0 02A0302D */   daddu    $a2, $s5, $zero
/* DE3084 80240BF4 0260202D */  daddu     $a0, $s3, $zero
/* DE3088 80240BF8 0280282D */  daddu     $a1, $s4, $zero
/* DE308C 80240BFC 0C0125AE */  jal       func_800496B8
/* DE3090 80240C00 02A0302D */   daddu    $a2, $s5, $zero
/* DE3094 80240C04 0809032B */  j         .L80240CAC
/* DE3098 80240C08 00000000 */   nop      
/* DE309C 80240C0C 0260202D */  daddu     $a0, $s3, $zero
/* DE30A0 80240C10 0280282D */  daddu     $a1, $s4, $zero
/* DE30A4 80240C14 0C0901FB */  jal       func_802407EC
/* DE30A8 80240C18 02A0302D */   daddu    $a2, $s5, $zero
/* DE30AC 80240C1C 0260202D */  daddu     $a0, $s3, $zero
/* DE30B0 80240C20 0280282D */  daddu     $a1, $s4, $zero
/* DE30B4 80240C24 0C09020F */  jal       func_8024083C
/* DE30B8 80240C28 02A0302D */   daddu    $a2, $s5, $zero
/* DE30BC 80240C2C 0809032B */  j         .L80240CAC
/* DE30C0 80240C30 00000000 */   nop      
/* DE30C4 80240C34 0260202D */  daddu     $a0, $s3, $zero
/* DE30C8 80240C38 0280282D */  daddu     $a1, $s4, $zero
/* DE30CC 80240C3C 0C01278F */  jal       func_80049E3C
/* DE30D0 80240C40 02A0302D */   daddu    $a2, $s5, $zero
/* DE30D4 80240C44 0260202D */  daddu     $a0, $s3, $zero
/* DE30D8 80240C48 0280282D */  daddu     $a1, $s4, $zero
/* DE30DC 80240C4C 0C0127B3 */  jal       func_80049ECC
/* DE30E0 80240C50 02A0302D */   daddu    $a2, $s5, $zero
/* DE30E4 80240C54 0809032B */  j         .L80240CAC
/* DE30E8 80240C58 00000000 */   nop      
/* DE30EC 80240C5C 0260202D */  daddu     $a0, $s3, $zero
/* DE30F0 80240C60 0280282D */  daddu     $a1, $s4, $zero
/* DE30F4 80240C64 0C0127DF */  jal       func_80049F7C
/* DE30F8 80240C68 02A0302D */   daddu    $a2, $s5, $zero
/* DE30FC 80240C6C 0260202D */  daddu     $a0, $s3, $zero
/* DE3100 80240C70 0280282D */  daddu     $a1, $s4, $zero
/* DE3104 80240C74 0C012849 */  jal       func_8004A124
/* DE3108 80240C78 02A0302D */   daddu    $a2, $s5, $zero
/* DE310C 80240C7C 8E630070 */  lw        $v1, 0x70($s3)
/* DE3110 80240C80 2402000E */  addiu     $v0, $zero, 0xe
/* DE3114 80240C84 14620009 */  bne       $v1, $v0, .L80240CAC
/* DE3118 80240C88 00000000 */   nop      
/* DE311C 80240C8C 0260202D */  daddu     $a0, $s3, $zero
/* DE3120 80240C90 0280282D */  daddu     $a1, $s4, $zero
/* DE3124 80240C94 0C0128FA */  jal       func_8004A3E8
/* DE3128 80240C98 02A0302D */   daddu    $a2, $s5, $zero
/* DE312C 80240C9C 0809032B */  j         .L80240CAC
/* DE3130 80240CA0 00000000 */   nop      
/* DE3134 80240CA4 0C0129CF */  jal       func_8004A73C
/* DE3138 80240CA8 0260202D */   daddu    $a0, $s3, $zero
.L80240CAC:
/* DE313C 80240CAC 8FBF0060 */  lw        $ra, 0x60($sp)
/* DE3140 80240CB0 8FB5005C */  lw        $s5, 0x5c($sp)
/* DE3144 80240CB4 8FB40058 */  lw        $s4, 0x58($sp)
/* DE3148 80240CB8 8FB30054 */  lw        $s3, 0x54($sp)
/* DE314C 80240CBC 8FB20050 */  lw        $s2, 0x50($sp)
/* DE3150 80240CC0 8FB1004C */  lw        $s1, 0x4c($sp)
/* DE3154 80240CC4 8FB00048 */  lw        $s0, 0x48($sp)
/* DE3158 80240CC8 0000102D */  daddu     $v0, $zero, $zero
/* DE315C 80240CCC 03E00008 */  jr        $ra
/* DE3160 80240CD0 27BD0068 */   addiu    $sp, $sp, 0x68
