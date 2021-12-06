.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_screen_overlay_params
/* CE4C0 80137DC0 10800005 */  beqz      $a0, .L80137DD8
/* CE4C4 80137DC4 24020001 */   addiu    $v0, $zero, 1
/* CE4C8 80137DC8 1082000A */  beq       $a0, $v0, .L80137DF4
/* CE4CC 80137DCC 00000000 */   nop
/* CE4D0 80137DD0 03E00008 */  jr        $ra
/* CE4D4 80137DD4 00000000 */   nop
.L80137DD8:
/* CE4D8 80137DD8 3C028015 */  lui       $v0, %hi(D_80156903)
/* CE4DC 80137DDC 90426903 */  lbu       $v0, %lo(D_80156903)($v0)
/* CE4E0 80137DE0 A0A20000 */  sb        $v0, ($a1)
/* CE4E4 80137DE4 3C018015 */  lui       $at, %hi(screen_overlay_frontZoom)
/* CE4E8 80137DE8 C4206904 */  lwc1      $f0, %lo(screen_overlay_frontZoom)($at)
/* CE4EC 80137DEC 03E00008 */  jr        $ra
/* CE4F0 80137DF0 E4C00000 */   swc1     $f0, ($a2)
.L80137DF4:
/* CE4F4 80137DF4 3C028015 */  lui       $v0, %hi(D_8015690B)
/* CE4F8 80137DF8 9042690B */  lbu       $v0, %lo(D_8015690B)($v0)
/* CE4FC 80137DFC A0A20000 */  sb        $v0, ($a1)
/* CE500 80137E00 3C018015 */  lui       $at, %hi(D_8015690C)
/* CE504 80137E04 C420690C */  lwc1      $f0, %lo(D_8015690C)($at)
/* CE508 80137E08 03E00008 */  jr        $ra
/* CE50C 80137E0C E4C00000 */   swc1     $f0, ($a2)
