.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_428A70
/* 428A70 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 428A74 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 428A78 802A9008 0080802D */  daddu     $s0, $a0, $zero
/* 428A7C 802A900C AFB10014 */  sw        $s1, 0x14($sp)
/* 428A80 802A9010 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 428A84 802A9014 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 428A88 802A9018 AFBF001C */  sw        $ra, 0x1c($sp)
/* 428A8C 802A901C AFB20018 */  sw        $s2, 0x18($sp)
/* 428A90 802A9020 8E12000C */  lw        $s2, 0xc($s0)
/* 428A94 802A9024 3C028029 */  lui       $v0, %hi(D_80294340)
/* 428A98 802A9028 24424340 */  addiu     $v0, $v0, %lo(D_80294340)
/* 428A9C 802A902C AE220434 */  sw        $v0, 0x434($s1)
/* 428AA0 802A9030 2402007F */  addiu     $v0, $zero, 0x7f
/* 428AA4 802A9034 A2200082 */  sb        $zero, 0x82($s1)
/* 428AA8 802A9038 0C09A216 */  jal       func_80268858
/* 428AAC 802A903C A2220086 */   sb       $v0, 0x86($s1)
/* 428AB0 802A9040 8E450000 */  lw        $a1, ($s2)
/* 428AB4 802A9044 0C0B1EAF */  jal       get_variable
/* 428AB8 802A9048 0200202D */   daddu    $a0, $s0, $zero
/* 428ABC 802A904C 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 428AC0 802A9050 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 428AC4 802A9054 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 428AC8 802A9058 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 428ACC 802A905C A602005A */  sh        $v0, 0x5a($s0)
/* 428AD0 802A9060 2402000D */  addiu     $v0, $zero, 0xd
/* 428AD4 802A9064 A602004A */  sh        $v0, 0x4a($s0)
/* 428AD8 802A9068 24020001 */  addiu     $v0, $zero, 1
/* 428ADC 802A906C A2020061 */  sb        $v0, 0x61($s0)
/* 428AE0 802A9070 2402001E */  addiu     $v0, $zero, 0x1e
/* 428AE4 802A9074 A600004C */  sh        $zero, 0x4c($s0)
/* 428AE8 802A9078 A2000060 */  sb        $zero, 0x60($s0)
/* 428AEC 802A907C A6000044 */  sh        $zero, 0x44($s0)
/* 428AF0 802A9080 A6000048 */  sh        $zero, 0x48($s0)
/* 428AF4 802A9084 A6000068 */  sh        $zero, 0x68($s0)
/* 428AF8 802A9088 A2200081 */  sb        $zero, 0x81($s1)
/* 428AFC 802A908C A2200084 */  sb        $zero, 0x84($s1)
/* 428B00 802A9090 A602006C */  sh        $v0, 0x6c($s0)
/* 428B04 802A9094 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 428B08 802A9098 A6020056 */  sh        $v0, 0x56($s0)
/* 428B0C 802A909C 24020050 */  addiu     $v0, $zero, 0x50
/* 428B10 802A90A0 3C01802B */  lui       $at, %hi(func_802A98B0)
/* 428B14 802A90A4 AC2098B0 */  sw        $zero, %lo(func_802A98B0)($at)
/* 428B18 802A90A8 0C050529 */  jal       create_icon
/* 428B1C 802A90AC A6020058 */   sh       $v0, 0x58($s0)
/* 428B20 802A90B0 0040882D */  daddu     $s1, $v0, $zero
/* 428B24 802A90B4 86050056 */  lh        $a1, 0x56($s0)
/* 428B28 802A90B8 86060058 */  lh        $a2, 0x58($s0)
/* 428B2C 802A90BC 0220202D */  daddu     $a0, $s1, $zero
/* 428B30 802A90C0 0C051261 */  jal       set_icon_render_pos
/* 428B34 802A90C4 AE110004 */   sw       $s1, 4($s0)
/* 428B38 802A90C8 0220202D */  daddu     $a0, $s1, $zero
/* 428B3C 802A90CC 0C051277 */  jal       func_801449DC
/* 428B40 802A90D0 0000282D */   daddu    $a1, $zero, $zero
/* 428B44 802A90D4 0220202D */  daddu     $a0, $s1, $zero
/* 428B48 802A90D8 0C051280 */  jal       set_icon_flags
/* 428B4C 802A90DC 24050082 */   addiu    $a1, $zero, 0x82
/* 428B50 802A90E0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 428B54 802A90E4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 428B58 802A90E8 0C050529 */  jal       create_icon
/* 428B5C 802A90EC 00000000 */   nop      
/* 428B60 802A90F0 0040882D */  daddu     $s1, $v0, $zero
/* 428B64 802A90F4 86050056 */  lh        $a1, 0x56($s0)
/* 428B68 802A90F8 86060058 */  lh        $a2, 0x58($s0)
/* 428B6C 802A90FC 0220202D */  daddu     $a0, $s1, $zero
/* 428B70 802A9100 AE110008 */  sw        $s1, 8($s0)
/* 428B74 802A9104 0C051261 */  jal       set_icon_render_pos
/* 428B78 802A9108 24C6001C */   addiu    $a2, $a2, 0x1c
/* 428B7C 802A910C 0220202D */  daddu     $a0, $s1, $zero
/* 428B80 802A9110 0C051277 */  jal       func_801449DC
/* 428B84 802A9114 0000282D */   daddu    $a1, $zero, $zero
/* 428B88 802A9118 0220202D */  daddu     $a0, $s1, $zero
/* 428B8C 802A911C 0C051280 */  jal       set_icon_flags
/* 428B90 802A9120 24050082 */   addiu    $a1, $zero, 0x82
/* 428B94 802A9124 3C048029 */  lui       $a0, %hi(D_80292974)
/* 428B98 802A9128 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 428B9C 802A912C 0C050529 */  jal       create_icon
/* 428BA0 802A9130 00000000 */   nop      
/* 428BA4 802A9134 0040882D */  daddu     $s1, $v0, $zero
/* 428BA8 802A9138 86050056 */  lh        $a1, 0x56($s0)
/* 428BAC 802A913C 86060058 */  lh        $a2, 0x58($s0)
/* 428BB0 802A9140 0220202D */  daddu     $a0, $s1, $zero
/* 428BB4 802A9144 AE11000C */  sw        $s1, 0xc($s0)
/* 428BB8 802A9148 0C051261 */  jal       set_icon_render_pos
/* 428BBC 802A914C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 428BC0 802A9150 0220202D */  daddu     $a0, $s1, $zero
/* 428BC4 802A9154 0C051277 */  jal       func_801449DC
/* 428BC8 802A9158 0000282D */   daddu    $a1, $zero, $zero
/* 428BCC 802A915C 0220202D */  daddu     $a0, $s1, $zero
/* 428BD0 802A9160 0C051280 */  jal       set_icon_flags
/* 428BD4 802A9164 24050082 */   addiu    $a1, $zero, 0x82
/* 428BD8 802A9168 8FBF001C */  lw        $ra, 0x1c($sp)
/* 428BDC 802A916C 8FB20018 */  lw        $s2, 0x18($sp)
/* 428BE0 802A9170 8FB10014 */  lw        $s1, 0x14($sp)
/* 428BE4 802A9174 8FB00010 */  lw        $s0, 0x10($sp)
/* 428BE8 802A9178 24020002 */  addiu     $v0, $zero, 2
/* 428BEC 802A917C 03E00008 */  jr        $ra
/* 428BF0 802A9180 27BD0020 */   addiu    $sp, $sp, 0x20
