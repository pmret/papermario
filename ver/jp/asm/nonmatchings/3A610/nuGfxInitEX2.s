.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxInitEX2
/* 3A610 8005F210 27BDF7E8 */  addiu     $sp, $sp, -0x818
/* 3A614 8005F214 AFBF0810 */  sw        $ra, 0x810($sp)
/* 3A618 8005F218 0C017FA8 */  jal       func_8005FEA0
/* 3A61C 8005F21C 00000000 */   nop
/* 3A620 8005F220 3C048009 */  lui       $a0, %hi(D_80093B78)
/* 3A624 8005F224 24843B78 */  addiu     $a0, $a0, %lo(D_80093B78)
/* 3A628 8005F228 0C017BE8 */  jal       func_8005EFA0
/* 3A62C 8005F22C 24050003 */   addiu    $a1, $zero, 3
/* 3A630 8005F230 3C028000 */  lui       $v0, 0x8000
/* 3A634 8005F234 34420400 */  ori       $v0, $v0, 0x400
/* 3A638 8005F238 3C048006 */  lui       $a0, %hi(D_80060000)
/* 3A63C 8005F23C 24840000 */  addiu     $a0, $a0, %lo(D_80060000)
/* 3A640 8005F240 3C01800A */  lui       $at, %hi(D_8009A5BC)
/* 3A644 8005F244 AC22A5BC */  sw        $v0, %lo(D_8009A5BC)($at)
/* 3A648 8005F248 0C017FF0 */  jal       func_8005FFC0
/* 3A64C 8005F24C 00000000 */   nop
/* 3A650 8005F250 3C028009 */  lui       $v0, %hi(D_80093B70)
/* 3A654 8005F254 24423B70 */  addiu     $v0, $v0, %lo(D_80093B70)
/* 3A658 8005F258 3C01800A */  lui       $at, %hi(D_8009A5F0)
/* 3A65C 8005F25C AC22A5F0 */  sw        $v0, %lo(D_8009A5F0)($at)
/* 3A660 8005F260 0C00B366 */  jal       func_8002CD98
/* 3A664 8005F264 00000000 */   nop
/* 3A668 8005F268 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A66C 8005F26C 27A50028 */  addiu     $a1, $sp, 0x28
/* 3A670 8005F270 00A42823 */  subu      $a1, $a1, $a0
/* 3A674 8005F274 3C02DE00 */  lui       $v0, 0xde00
/* 3A678 8005F278 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A67C 8005F27C 3C020009 */  lui       $v0, 9
/* 3A680 8005F280 24423B88 */  addiu     $v0, $v0, 0x3b88
/* 3A684 8005F284 AC820004 */  sw        $v0, 4($a0)
/* 3A688 8005F288 3C02E900 */  lui       $v0, 0xe900
/* 3A68C 8005F28C AFA20018 */  sw        $v0, 0x18($sp)
/* 3A690 8005F290 3C02DF00 */  lui       $v0, 0xdf00
/* 3A694 8005F294 0000302D */  daddu     $a2, $zero, $zero
/* 3A698 8005F298 00C0382D */  daddu     $a3, $a2, $zero
/* 3A69C 8005F29C AFA0001C */  sw        $zero, 0x1c($sp)
/* 3A6A0 8005F2A0 AFA20020 */  sw        $v0, 0x20($sp)
/* 3A6A4 8005F2A4 0C00B3C9 */  jal       func_8002CF24
/* 3A6A8 8005F2A8 AFA00024 */   sw       $zero, 0x24($sp)
/* 3A6AC 8005F2AC 0C017BE0 */  jal       func_8005EF80
/* 3A6B0 8005F2B0 00000000 */   nop
/* 3A6B4 8005F2B4 8FBF0810 */  lw        $ra, 0x810($sp)
/* 3A6B8 8005F2B8 03E00008 */  jr        $ra
/* 3A6BC 8005F2BC 27BD0818 */   addiu    $sp, $sp, 0x818
