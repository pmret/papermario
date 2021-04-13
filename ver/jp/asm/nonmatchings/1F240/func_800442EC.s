.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800442EC
/* 1F6EC 800442EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1F6F0 800442F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1F6F4 800442F4 0080882D */  daddu     $s1, $a0, $zero
/* 1F6F8 800442F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1F6FC 800442FC AFB00010 */  sw        $s0, 0x10($sp)
/* 1F700 80044300 8E300148 */  lw        $s0, 0x148($s1)
/* 1F704 80044304 0C00E9EB */  jal       func_8003A7AC
/* 1F708 80044308 86040008 */   lh       $a0, 8($s0)
/* 1F70C 8004430C 0220202D */  daddu     $a0, $s1, $zero
/* 1F710 80044310 0C0B0FCF */  jal       func_802C3F3C
/* 1F714 80044314 0040882D */   daddu    $s1, $v0, $zero
/* 1F718 80044318 3C048007 */  lui       $a0, %hi(D_80077E08)
/* 1F71C 8004431C 24847E08 */  addiu     $a0, $a0, %lo(D_80077E08)
/* 1F720 80044320 8E0200CC */  lw        $v0, 0xcc($s0)
/* 1F724 80044324 2405000A */  addiu     $a1, $zero, 0xa
/* 1F728 80044328 8C420018 */  lw        $v0, 0x18($v0)
/* 1F72C 8004432C 0000302D */  daddu     $a2, $zero, $zero
/* 1F730 80044330 0C0B0CF8 */  jal       func_802C33E0
/* 1F734 80044334 AE220028 */   sw       $v0, 0x28($s1)
/* 1F738 80044338 0040182D */  daddu     $v1, $v0, $zero
/* 1F73C 8004433C AE030048 */  sw        $v1, 0x48($s0)
/* 1F740 80044340 8C620144 */  lw        $v0, 0x144($v1)
/* 1F744 80044344 AE020060 */  sw        $v0, 0x60($s0)
/* 1F748 80044348 AC700148 */  sw        $s0, 0x148($v1)
/* 1F74C 8004434C 86020008 */  lh        $v0, 8($s0)
/* 1F750 80044350 AC62014C */  sw        $v0, 0x14c($v1)
/* 1F754 80044354 92040006 */  lbu       $a0, 6($s0)
/* 1F758 80044358 A0640004 */  sb        $a0, 4($v1)
/* 1F75C 8004435C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1F760 80044360 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F764 80044364 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F768 80044368 240200FF */  addiu     $v0, $zero, 0xff
/* 1F76C 8004436C 03E00008 */  jr        $ra
/* 1F770 80044370 27BD0020 */   addiu    $sp, $sp, 0x20
