.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DFC74
/* 79124 800DFC74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79128 800DFC78 AFB00010 */  sw        $s0, 0x10($sp)
/* 7912C 800DFC7C 3C108011 */  lui       $s0, 0x8011
/* 79130 800DFC80 2610EFC8 */  addiu     $s0, $s0, -0x1038
/* 79134 800DFC84 0200202D */  daddu     $a0, $s0, $zero
/* 79138 800DFC88 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7913C 800DFC8C 0C00A580 */  jal       mem_clear
/* 79140 800DFC90 24050288 */   addiu    $a1, $zero, 0x288
/* 79144 800DFC94 24020001 */  addiu     $v0, $zero, 1
/* 79148 800DFC98 0C038817 */  jal       func_800E205C
/* 7914C 800DFC9C AE020000 */   sw       $v0, ($s0)
/* 79150 800DFCA0 8E050028 */  lw        $a1, 0x28($s0)
/* 79154 800DFCA4 8E06002C */  lw        $a2, 0x2c($s0)
/* 79158 800DFCA8 8E070030 */  lw        $a3, 0x30($s0)
/* 7915C 800DFCAC 0C044898 */  jal       create_shadow_type
/* 79160 800DFCB0 0000202D */   daddu    $a0, $zero, $zero
/* 79164 800DFCB4 0C039ADA */  jal       func_800E6B68
/* 79168 800DFCB8 AE0200CC */   sw       $v0, 0xcc($s0)
/* 7916C 800DFCBC 0C0382C5 */  jal       func_800E0B14
/* 79170 800DFCC0 00000000 */   nop      
/* 79174 800DFCC4 0C0381A7 */  jal       func_800E069C
/* 79178 800DFCC8 00000000 */   nop      
/* 7917C 800DFCCC 0C038145 */  jal       func_800E0514
/* 79180 800DFCD0 00000000 */   nop      
/* 79184 800DFCD4 0C0380DD */  jal       func_800E0374
/* 79188 800DFCD8 00000000 */   nop      
/* 7918C 800DFCDC 0C039548 */  jal       func_800E5520
/* 79190 800DFCE0 00000000 */   nop      
/* 79194 800DFCE4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 79198 800DFCE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7919C 800DFCEC 03E00008 */  jr        $ra
/* 791A0 800DFCF0 27BD0018 */   addiu    $sp, $sp, 0x18
