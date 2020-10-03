.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80127B70
/* BE270 80127B70 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE274 80127B74 24020004 */  addiu     $v0, $zero, 4
/* BE278 80127B78 0000282D */  daddu     $a1, $zero, $zero
/* BE27C 80127B7C 00A0302D */  daddu     $a2, $a1, $zero
/* BE280 80127B80 00A0382D */  daddu     $a3, $a1, $zero
/* BE284 80127B84 AFBF0020 */  sw        $ra, 0x20($sp)
/* BE288 80127B88 AFA00010 */  sw        $zero, 0x10($sp)
/* BE28C 80127B8C AFA20014 */  sw        $v0, 0x14($sp)
/* BE290 80127B90 0C049F64 */  jal       func_80127D90
/* BE294 80127B94 AFA00018 */   sw       $zero, 0x18($sp)
/* BE298 80127B98 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE29C 80127B9C 03E00008 */  jr        $ra
/* BE2A0 80127BA0 27BD0028 */   addiu    $sp, $sp, 0x28
