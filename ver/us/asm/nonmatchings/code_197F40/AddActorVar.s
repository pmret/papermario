.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AddActorVar
/* 19A9B4 8026C0D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19A9B8 8026C0D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 19A9BC 8026C0DC 0080902D */  daddu     $s2, $a0, $zero
/* 19A9C0 8026C0E0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19A9C4 8026C0E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 19A9C8 8026C0E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A9CC 8026C0EC 8E50000C */  lw        $s0, 0xc($s2)
/* 19A9D0 8026C0F0 8E050000 */  lw        $a1, ($s0)
/* 19A9D4 8026C0F4 0C0B1EAF */  jal       get_variable
/* 19A9D8 8026C0F8 26100004 */   addiu    $s0, $s0, 4
/* 19A9DC 8026C0FC 0040882D */  daddu     $s1, $v0, $zero
/* 19A9E0 8026C100 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19A9E4 8026C104 16220002 */  bne       $s1, $v0, .L8026C110
/* 19A9E8 8026C108 00000000 */   nop      
/* 19A9EC 8026C10C 8E510148 */  lw        $s1, 0x148($s2)
.L8026C110:
/* 19A9F0 8026C110 8E050000 */  lw        $a1, ($s0)
/* 19A9F4 8026C114 26100004 */  addiu     $s0, $s0, 4
/* 19A9F8 8026C118 0C0B1EAF */  jal       get_variable
/* 19A9FC 8026C11C 0240202D */   daddu    $a0, $s2, $zero
/* 19AA00 8026C120 0240202D */  daddu     $a0, $s2, $zero
/* 19AA04 8026C124 8E050000 */  lw        $a1, ($s0)
/* 19AA08 8026C128 0C0B1EAF */  jal       get_variable
/* 19AA0C 8026C12C 0040802D */   daddu    $s0, $v0, $zero
/* 19AA10 8026C130 0220202D */  daddu     $a0, $s1, $zero
/* 19AA14 8026C134 0C09A75B */  jal       get_actor
/* 19AA18 8026C138 0040882D */   daddu    $s1, $v0, $zero
/* 19AA1C 8026C13C 2444000C */  addiu     $a0, $v0, 0xc
/* 19AA20 8026C140 00108080 */  sll       $s0, $s0, 2
/* 19AA24 8026C144 00902021 */  addu      $a0, $a0, $s0
/* 19AA28 8026C148 8C83007C */  lw        $v1, 0x7c($a0)
/* 19AA2C 8026C14C 00711821 */  addu      $v1, $v1, $s1
/* 19AA30 8026C150 AC83007C */  sw        $v1, 0x7c($a0)
/* 19AA34 8026C154 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19AA38 8026C158 8FB20018 */  lw        $s2, 0x18($sp)
/* 19AA3C 8026C15C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19AA40 8026C160 8FB00010 */  lw        $s0, 0x10($sp)
/* 19AA44 8026C164 24020002 */  addiu     $v0, $zero, 2
/* 19AA48 8026C168 03E00008 */  jr        $ra
/* 19AA4C 8026C16C 27BD0020 */   addiu    $sp, $sp, 0x20
