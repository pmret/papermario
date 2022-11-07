.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425E0_854750
/* 854750 802425E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 854754 802425E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 854758 802425E8 10A00003 */  beqz      $a1, .L802425F8
/* 85475C 802425EC 8C86000C */   lw       $a2, 0xc($a0)
/* 854760 802425F0 3C018024 */  lui       $at, %hi(mac_05_ItemChoice_HasSelectedItem)
/* 854764 802425F4 AC2076D8 */  sw        $zero, %lo(mac_05_ItemChoice_HasSelectedItem)($at)
.L802425F8:
/* 854768 802425F8 3C038024 */  lui       $v1, %hi(mac_05_ItemChoice_HasSelectedItem)
/* 85476C 802425FC 246376D8 */  addiu     $v1, $v1, %lo(mac_05_ItemChoice_HasSelectedItem)
/* 854770 80242600 8C620000 */  lw        $v0, ($v1)
/* 854774 80242604 54400003 */  bnel      $v0, $zero, .L80242614
/* 854778 80242608 AC600000 */   sw       $zero, ($v1)
/* 85477C 8024260C 0809098A */  j         .L80242628
/* 854780 80242610 0000102D */   daddu    $v0, $zero, $zero
.L80242614:
/* 854784 80242614 8CC50000 */  lw        $a1, ($a2)
/* 854788 80242618 3C068024 */  lui       $a2, %hi(mac_05_ItemChoice_SelectedItemID)
/* 85478C 8024261C 0C0B2026 */  jal       evt_set_variable
/* 854790 80242620 8CC676DC */   lw       $a2, %lo(mac_05_ItemChoice_SelectedItemID)($a2)
/* 854794 80242624 24020002 */  addiu     $v0, $zero, 2
.L80242628:
/* 854798 80242628 8FBF0010 */  lw        $ra, 0x10($sp)
/* 85479C 8024262C 03E00008 */  jr        $ra
/* 8547A0 80242630 27BD0018 */   addiu    $sp, $sp, 0x18
