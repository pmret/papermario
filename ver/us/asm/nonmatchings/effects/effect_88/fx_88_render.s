.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_88_render
/* 3B40A8 E00B01F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B40AC E00B01FC 3C02E00B */  lui       $v0, %hi(func_E00B0234)
/* 3B40B0 E00B0200 24420234 */  addiu     $v0, $v0, %lo(func_E00B0234)
/* 3B40B4 E00B0204 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B40B8 E00B0208 2402000A */  addiu     $v0, $zero, 0xa
/* 3B40BC E00B020C AFA20014 */  sw        $v0, 0x14($sp)
/* 3B40C0 E00B0210 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B40C4 E00B0214 AFA40018 */  sw        $a0, 0x18($sp)
/* 3B40C8 E00B0218 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B40CC E00B021C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B40D0 E00B0220 0C080120 */  jal       shim_queue_render_task
/* 3B40D4 E00B0224 AFA20010 */   sw       $v0, 0x10($sp)
/* 3B40D8 E00B0228 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B40DC E00B022C 03E00008 */  jr        $ra
/* 3B40E0 E00B0230 27BD0028 */   addiu    $sp, $sp, 0x28
