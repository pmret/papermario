.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel FullyRestoreSP
/* F6890 802D1EE0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* F6894 802D1EE4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* F6898 802D1EE8 8062028E */  lb        $v0, 0x28e($v1)
/* F689C 802D1EEC 00021200 */  sll       $v0, $v0, 8
/* F68A0 802D1EF0 A4620290 */  sh        $v0, 0x290($v1)
/* F68A4 802D1EF4 03E00008 */  jr        $ra
/* F68A8 802D1EF8 24020002 */   addiu    $v0, $zero, 2
