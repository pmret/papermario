.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_entity_fog_color
/* B977C 8012307C 3C028015 */  lui       $v0, %hi(D_8015437C)
/* B9780 80123080 8C42437C */  lw        $v0, %lo(D_8015437C)($v0)
/* B9784 80123084 AC820000 */  sw        $v0, ($a0)
/* B9788 80123088 3C028015 */  lui       $v0, %hi(D_80154380)
/* B978C 8012308C 8C424380 */  lw        $v0, %lo(D_80154380)($v0)
/* B9790 80123090 ACA20000 */  sw        $v0, ($a1)
/* B9794 80123094 3C028015 */  lui       $v0, %hi(D_80154384)
/* B9798 80123098 8C424384 */  lw        $v0, %lo(D_80154384)($v0)
/* B979C 8012309C ACC20000 */  sw        $v0, ($a2)
/* B97A0 801230A0 3C028015 */  lui       $v0, %hi(D_80154388)
/* B97A4 801230A4 8C424388 */  lw        $v0, %lo(D_80154388)($v0)
/* B97A8 801230A8 03E00008 */  jr        $ra
/* B97AC 801230AC ACE20000 */   sw       $v0, ($a3)
