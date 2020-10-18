.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100
/* 317020 802BD100 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 317024 802BD104 AFB10014 */  sw        $s1, 0x14($sp)
/* 317028 802BD108 0080882D */  daddu     $s1, $a0, $zero
/* 31702C 802BD10C AFB00010 */  sw        $s0, 0x10($sp)
/* 317030 802BD110 0000802D */  daddu     $s0, $zero, $zero
/* 317034 802BD114 AFBF0018 */  sw        $ra, 0x18($sp)
.L802BD118:
/* 317038 802BD118 0C051734 */  jal       get_trigger_by_id
/* 31703C 802BD11C 0200202D */   daddu    $a0, $s0, $zero
/* 317040 802BD120 0040182D */  daddu     $v1, $v0, $zero
/* 317044 802BD124 1060000B */  beqz      $v1, .L802BD154
/* 317048 802BD128 26100001 */   addiu    $s0, $s0, 1
/* 31704C 802BD12C 8C620000 */  lw        $v0, ($v1)
/* 317050 802BD130 30420100 */  andi      $v0, $v0, 0x100
/* 317054 802BD134 10400007 */  beqz      $v0, .L802BD154
/* 317058 802BD138 00000000 */   nop      
/* 31705C 802BD13C 8C620008 */  lw        $v0, 8($v1)
/* 317060 802BD140 14510005 */  bne       $v0, $s1, .L802BD158
/* 317064 802BD144 2A020040 */   slti     $v0, $s0, 0x40
/* 317068 802BD148 8C62002C */  lw        $v0, 0x2c($v1)
/* 31706C 802BD14C 080AF458 */  j         .L802BD160
/* 317070 802BD150 00000000 */   nop      
.L802BD154:
/* 317074 802BD154 2A020040 */  slti      $v0, $s0, 0x40
.L802BD158:
/* 317078 802BD158 1440FFEF */  bnez      $v0, .L802BD118
/* 31707C 802BD15C 0000102D */   daddu    $v0, $zero, $zero
.L802BD160:
/* 317080 802BD160 8FBF0018 */  lw        $ra, 0x18($sp)
/* 317084 802BD164 8FB10014 */  lw        $s1, 0x14($sp)
/* 317088 802BD168 8FB00010 */  lw        $s0, 0x10($sp)
/* 31708C 802BD16C 03E00008 */  jr        $ra
/* 317090 802BD170 27BD0020 */   addiu    $sp, $sp, 0x20
