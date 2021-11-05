.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxDisplayOn
/* 3A4E0 8005F0E0 24020080 */  addiu     $v0, $zero, 0x80
/* 3A4E4 8005F0E4 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 3A4E8 8005F0E8 AC22A5D8 */  sw        $v0, %lo(D_8009A5D8)($at)
/* 3A4EC 8005F0EC 03E00008 */  jr        $ra
/* 3A4F0 8005F0F0 00000000 */   nop
/* 3A4F4 8005F0F4 00000000 */  nop
/* 3A4F8 8005F0F8 00000000 */  nop
/* 3A4FC 8005F0FC 00000000 */  nop
